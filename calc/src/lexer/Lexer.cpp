#include "Lexer.h"

Lexer::Lexer(string text)
{
    this->text = text;
    pos = 0;
    current_char = this->text[pos];
}

void Lexer::nextChar()
{
    pos++;
    if (pos >= text.size())
    {
        current_char = 0;
    }
    else
    {
        current_char = text[pos];
    }
}

void Lexer::skipWhitespace()
{
    while (isWhitespace() && notNULL())
    {
        nextChar();
    }
}

// get multidigit number
double Lexer::getNumber()
{
    string output = "";

    while ((isDigit() || isDecimalPoint()) && notNULL())
    {
        output += current_char;
        nextChar();
    }

    return atof(output.c_str());
}

string Lexer::getFunctionName()
{
    string output = "";

    while (isAlphanumeric() && notNULL())
    {
        output += current_char;
        nextChar();
    }

    return output;
}

Token Lexer::getNextToken()
{
    while (notNULL())
    {
        if (isWhitespace())
        {
            skipWhitespace();
            continue;
        }

        if (isDigit()) return Token(INTEGER, getNumber());

        if (current_char == '!') { nextChar(); return Token(FACTORIAL, '+'); }
        if (current_char == '?') { nextChar(); return Token(NTH_TRIANGLE, '+'); }
        if (current_char == '^') { nextChar(); return Token(POWER, '^'); }
        if (current_char == '*') { nextChar(); return Token(MULT, '*'); }
        if (current_char == '/') { nextChar(); return Token(DIV, '/'); }
        if (current_char == '%') { nextChar(); return Token(MODULUS, '%'); }
        if (current_char == '+') { nextChar(); return Token(ADD, '+'); }
        if (current_char == '-') { nextChar(); return Token(SUB, '-'); }
        if (current_char == '(') { nextChar(); return Token(L_PAREN, '('); }
        if (current_char == ')') { nextChar(); return Token(R_PAREN, ')'); }

        if (isAlphanumeric()) { return Token(FUNCTION, getFunctionName()); }

        printf("[ERROR] Invaid token '%c' on position %i.\n", current_char, pos);
        break;
    }

    return Token(__EOF, (char) 0);
}

bool Lexer::isLetter()
{
    bool isLowercase = current_char >= 'a' && current_char <= 'z';
    bool isUppercase = current_char >= 'A' && current_char <= 'Z';
    return isLowercase || isUppercase;
}

bool Lexer::isDigit()
{
    return current_char >= '0' && current_char <= '9';
}

bool Lexer::isAlphanumeric()
{
    return isLetter() || isDigit();
}

bool Lexer::isDecimalPoint()
{
    return current_char == '.';
}

bool Lexer::isWhitespace()
{
    return current_char == ' ';
}

bool Lexer::notNULL()
{
    return current_char != 0;
}