#pragma once

#include <string>
using std::string;

enum TokenType
{
    __EOF,
    WHITESPACE,
    R_PAREN,
    L_PAREN,
    FACTORIAL,
    NTH_TRIANGLE,
    POWER,
    MULT,
    DIV,
    MODULUS,
    ADD,
    SUB,
    INTEGER,
    FUNCTION
};

class Token
{
    public:
        TokenType type;
        char symbol;
        double value;
        string function_name;

        Token(TokenType type, double value);
        Token(TokenType type, char binop_symbol);
        Token(TokenType type, string function_name);
};