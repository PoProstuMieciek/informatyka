#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "../lexer/Lexer.h"

class BinOp
{
    public:
        TokenType type;
        BinOp *left = nullptr;
        BinOp *right = nullptr;
        double value;

        BinOp(TokenType type, double value);
        BinOp(TokenType type, BinOp *left = nullptr, BinOp *right = nullptr);
};

class Parser
{
    public:
        Lexer *lexer;
        Token current_token = Token(__EOF, (char) 0);

        Parser(Lexer *lexer);

        void eat(TokenType token_type);

        BinOp *factor();
        BinOp *term();
        BinOp *expression();

        BinOp *parse();
};