#include "Parser.h"

BinOp::BinOp(TokenType type, double value)
{
    this->type = type;
    this->value = value;
}

BinOp::BinOp(TokenType type, string function_name)
{
    this->type = type;
    this->function_name = function_name;
}

BinOp::BinOp(TokenType type, BinOp *left, BinOp *right)
{
    this->type = type;
    this->left = left;
    this->right = right;
}

Parser::Parser(Lexer *lexer)
{
    this->lexer = lexer;
    this->current_token = this->lexer->getNextToken();
}

void Parser::eat(TokenType token_type)
{
    if (current_token.type == token_type)
    {
        current_token = lexer->getNextToken();
    }
    else
    {
        printf("[ERROR] Invalid syntax. Unexpected token '%c' on position %i.\n", current_token.symbol, lexer->pos);
        exit(1);
    }
}

BinOp *Parser::factor()
{
    // FACTOR: TOKEN(INTEGER) | L_PAREN EXPRESSION R_PAREN

    if (current_token.type == INTEGER)
    {
        BinOp *node = new BinOp(INTEGER, current_token.value);
        eat(INTEGER);

        if (current_token.type == FACTORIAL)
        {
            node = new BinOp(FACTORIAL, node);
            eat(FACTORIAL);
        }
        if (current_token.type == NTH_TRIANGLE)
        {
            node = new BinOp(NTH_TRIANGLE, node);
            eat(NTH_TRIANGLE);
        }

        return node;
    }
    else if (current_token.type == L_PAREN)
    {
        eat(L_PAREN);
        BinOp *node = expression();
        eat(R_PAREN);
        return node;
    }
    else if (current_token.type == R_PAREN)
    {
        return new BinOp(__EOF, 0.0);
    }
    else if (current_token.type == FUNCTION)
    {
        BinOp *node = new BinOp(FUNCTION, current_token.function_name);
        eat(FUNCTION);
        node->left = factor();
        return node;
    }

    printf("[ERROR] Invalid syntax. Unexpected token '%c' on position %i.\n", current_token.symbol, lexer->pos - 1);
    exit(1);
}

BinOp *Parser::term()
{
    // TERM: FACTOR ((MULT | DIV) FACTOR)*
    BinOp *node = factor();

    while (current_token.type == POWER || current_token.type == MULT || current_token.type == DIV || current_token.type == MODULUS)
    {
        if (current_token.type == POWER)
        {
            eat(POWER);
            node = new BinOp(POWER, node, factor());
        }
        else if (current_token.type == MULT)
        {
            eat(MULT);
            node = new BinOp(MULT, node, factor());
        }
        else if (current_token.type == DIV)
        {
            eat(DIV);
            node = new BinOp(DIV, node, factor());
        }
        else if (current_token.type == MODULUS)
        {
            eat(MODULUS);
            node = new BinOp(MODULUS, node, factor());
        }
    }

    return node;
}

BinOp *Parser::expression()
{
    // EXPRESSION: TERM ((ADD | SUB) TERM)*
    BinOp *node = term();

    while (current_token.type == ADD || current_token.type == SUB)
    {
        if (current_token.type == ADD)
        {
            eat(ADD);
            node = new BinOp(ADD, node, term());
        }
        else if (current_token.type == SUB)
        {
            eat(SUB);
            node = new BinOp(SUB, node, term());
        }
    }

    return node;
}

BinOp *Parser::parse()
{
    return expression();
}