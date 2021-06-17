// Copyright (C) 2021  Maciej Opaliński. All Rights Reserved.

#include <bits/stdc++.h>
using namespace std;

#include "token/Token.h"
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "evaluator/Evaluator.h"

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
            printf("Operators: + - * / ! ? ^ %%\n");
            printf("Functions: sin() cos() tan() pi() rad() deg() sqrt() cbrt()\n");
            continue;
        }

        Lexer lexer = Lexer(input);
        Parser parser = Parser(&lexer);
        Evaluator evaluator = Evaluator(&parser);

        auto root = parser.parse();
        if (!root) continue;

        if (input[0] == ' ') root->debug();

        auto output = evaluator.evaluate(root);
        printf("%f\n", output);
    }
}