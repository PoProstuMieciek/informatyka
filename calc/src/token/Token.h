#pragma once

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
    ADD,
    SUB,
    INTEGER
};

class Token
{
    public:
        TokenType type;
        char symbol;
        double value;

        Token(TokenType type, double value);
        Token(TokenType type, char symbol);
};