#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "../parser/Parser.h"

class Evaluator
{
    public:
        Parser *parser;

        Evaluator(Parser *parser);

        double evaluate(BinOp *node);
        double evaluate_function(string function_name, double arg1);

        double factorial(int n);
        double nth_triangle_number(int n);
        double power(double a, int b);
};