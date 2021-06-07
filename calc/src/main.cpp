// Copyright (C) 2021  Maciej Opaliński. All Rights Reserved.

#include <bits/stdc++.h>
using namespace std;

#include "token/Token.h"
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "evaluator/Evaluator.h"

const char *enumToType(TokenType type)
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

void debug(BinOp *node, int index = 1)
{
    if (!node || index <= 0) return;

    int left = index * 2, right = left + 1;

    if (!node->left) left = -1;
    if (!node->right) right = -1;

    printf("%i: BinOp(type=%s, left=%i, right=%i) = %f\n", index, enumToType(node->type), left, right, node->value);

    debug(node->left, left);
    debug(node->right, right);
}

int main()
{
    string last_input = "";

    printf("Type 'help' to display all operators. Type 'exit' to quit the program.\n");

    while (true)
    {
        printf("> ");
        string input;
        getline(cin, input);

        if (input == "\033[A")
        {
            input = last_input;
            printf("> %s\n", last_input.c_str());
        }
        last_input = input;

        if (input.empty()) continue;
        if (input == "exit") exit(0);
        if (input == "help")
        {
            printf("Operators: + - * / ! ? ^ %%/n");
            printf("Functions: sin() cos() tan() pi() rad() deg() sqrt() cbrt()\n");
            continue;
        }

        Lexer lexer = Lexer(input);
        Parser parser = Parser(&lexer);
        Evaluator evaluator = Evaluator(&parser);

        auto root = parser.parse();
        if (input[0] == ' ') debug(root);

        auto output = evaluator.evaluate(root);
        printf("%f\n", output);
    }
}
