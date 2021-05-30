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