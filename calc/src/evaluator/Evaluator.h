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

        double factorial(int n);
        double nth_triangle_number(int n);
        double power(double a, int b);
};