#include "Evaluator.h"

Evaluator::Evaluator(Parser *parser)
{
    this->parser = parser;
}

double Evaluator::factorial(int n)
{
    if (n == 1) return n;
    else return n * factorial(n - 1);
}

double Evaluator::nth_triangle_number(int n)
{
    if (n == 1) return n;
    else return n + nth_triangle_number(n - 1);
}

double Evaluator::power(double a, int b)
{
    if (b == 1) return a;
    else return a * power(a, b - 1);
}

double Evaluator::evaluate(BinOp *node)
{
    if (node->type == INTEGER) return node->value;

    if (node->type == FACTORIAL)
    {
        auto left = evaluate(node->left);
        return factorial((int) left);
    }
    if (node->type == NTH_TRIANGLE)
    {
        auto left = evaluate(node->left);
        return nth_triangle_number((int) left);
    }
    if (node->type == POWER)
    {
        auto left = evaluate(node->left);
        auto right = evaluate(node->right);
        return power(left, right);
    }
    if (node->type == MULT)
    {
        auto left = evaluate(node->left);
        auto right = evaluate(node->right);
        return left * right;
    }
    if (node->type == DIV)
    {
        auto left = evaluate(node->left);
        auto right = evaluate(node->right);
        return left / right;
    }
    if (node->type == MODULUS)
    {
        auto left = evaluate(node->left);
        auto right = evaluate(node->right);
        return (int) left % (int) right;
    }
    if (node->type == ADD)
    {
        auto left = evaluate(node->left);
        auto right = evaluate(node->right);
        return left + right;
    }
    if (node->type == SUB)
    {
        auto left = evaluate(node->left);
        auto right = evaluate(node->right);
        return left - right;
    }

    return 0;
}