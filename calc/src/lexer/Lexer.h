#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "../token/Token.h"

class Lexer
{
    public:
        string text;
        uint32_t pos;
        char current_char;

        Lexer(string text);

        void nextChar();
        void skipWhitespace();

        double getNumber();
        string getFunctionName();
        Token getNextToken();

        bool isLetter();
        bool isDigit();
        bool isAlphanumeric();
        bool isDecimalPoint();
        bool isWhitespace();
        bool notNULL();
};