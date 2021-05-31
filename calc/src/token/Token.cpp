#include "Token.h"

Token::Token(TokenType type, double value)
{
    this->type = type;
    this->value = value;
}

Token::Token(TokenType type, char symbol)
{
    this->type = type;
    this->symbol = symbol;
}

Token::Token(TokenType type, string function_name)
{
    this->type = type;
    this->function_name = function_name;
}