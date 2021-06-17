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

const char *BinOp::typeToString()
{
    if (type == FACTORIAL) return "FACTORIAL";
    if (type == NTH_TRIANGLE) return "NTH_TRIANGLE";
    if (type == POWER) return "POWER";
    if (type == MULT) return "MULT";
    if (type == DIV) return "DIV";
    if (type == ADD) return "ADD";
    if (type == SUB) return "SUB";
    if (type == INTEGER) return "INTEGER";
    if (type == FUNCTION) return "FUNCTION";

    return "NULL";
}

void BinOp::debug(int index)
{
    if (index <= 0) return;

    int left_index  = index * 2;
    int right_index = index * 2 + 1;
    if (!this->left) left_index = -1;
    if (!this->right) right_index = -1;

    printf("%i: BinOp(type=%s, left=%i, right=%i, value=%f, func_name='%s')\n", index, typeToString(), left_index, right_index, value, function_name.c_str());

    if (this->left) left->debug(left_index);
    if (this->right) right->debug(right_index);
}

Parser::Parser(Lexer *lexer)
{
    this->lexer = lexer;
    this->current_token = this->lexer->getNextToken();
}

bool Parser::eat(TokenType token_type)
{
    if (current_token.type == token_type)
    {
        current_token = lexer->getNextToken();
        return true;
    }
    else
    {
        printf("[ERROR] Invalid syntax. Unexpected token '%c' on position %i.\n", current_token.symbol, lexer->pos);
        return false;
    }
}

BinOp *Parser::factor()
{
    // FACTOR: TOKEN(INTEGER) | L_PAREN EXPRESSION R_PAREN

    if (current_token.type == INTEGER)
    {
        BinOp *node = new BinOp(INTEGER, current_token.value);
        if (!eat(INTEGER)) return nullptr;

        if (current_token.type == FACTORIAL)
        {
            node = new BinOp(FACTORIAL, node);
            if (!eat(FACTORIAL)) return nullptr;
        }
        if (current_token.type == NTH_TRIANGLE)
        {
            node = new BinOp(NTH_TRIANGLE, node);
            if (!eat(NTH_TRIANGLE)) return nullptr;
        }

        return node;
    }
    else if (current_token.type == L_PAREN)
    {
        if (!eat(L_PAREN)) return nullptr;

        BinOp *node = expression();
        if (!node) return nullptr;

        if (!eat(R_PAREN)) return nullptr;
        return node;
    }
    else if (current_token.type == R_PAREN)
    {
        return new BinOp(__EOF, 0.0);
    }
    else if (current_token.type == FUNCTION)
    {
        BinOp *node = new BinOp(FUNCTION, current_token.function_name);
        if (!eat(FUNCTION)) return nullptr;

        node->left = factor();
        if (!node->left) return nullptr;

        return node;
    }

    printf("[ERROR] Invalid syntax. Unexpected token '%c' on position %i.\n", current_token.symbol, lexer->pos - 1);
    return nullptr;
}

BinOp *Parser::term()
{
    // TERM: FACTOR ((MULT | DIV) FACTOR)*
    BinOp *node = factor();
    if (!node) return nullptr;

    while (current_token.type == POWER || current_token.type == MULT || current_token.type == DIV || current_token.type == MODULUS)
    {
        if (current_token.type == POWER)
        {
            if (!eat(POWER)) return nullptr;
            node = new BinOp(POWER, node, factor());
            if (!node->right) return nullptr;
        }
        else if (current_token.type == MULT)
        {
            if (!eat(MULT)) return nullptr;
            node = new BinOp(MULT, node, factor());
            if (!node->right) return nullptr;
        }
        else if (current_token.type == DIV)
        {
            if (!eat(DIV)) return nullptr;
            node = new BinOp(DIV, node, factor());
            if (!node->right) return nullptr;
        }
        else if (current_token.type == MODULUS)
        {
            if (!eat(MODULUS)) return nullptr;
            node = new BinOp(MODULUS, node, factor());
            if (!node->right) return nullptr;
        }
    }

    return node;
}

BinOp *Parser::expression()
{
    // EXPRESSION: TERM ((ADD | SUB) TERM)*
    BinOp *node = term();
    if (!node) return nullptr;

    while (current_token.type == ADD || current_token.type == SUB)
    {
        if (current_token.type == ADD)
        {
            if (!eat(ADD)) return nullptr;
            node = new BinOp(ADD, node, term());
            if (!node->right) return nullptr;
        }
        else if (current_token.type == SUB)
        {
            if (!eat(SUB)) return nullptr;
            node = new BinOp(SUB, node, term());
            if (!node->right) return nullptr;
        }
    }

    return node;
}

BinOp *Parser::parse()
{
    return expression();
}