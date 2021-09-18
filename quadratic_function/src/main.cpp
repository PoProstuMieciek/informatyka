#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

pair<double, double> find_quadratic_function_solution(double a, double b, double c)
{
    double delta = b * b - 4.0 * a * c;

    if (a == 0) goto invalid;

    if (delta == 0)
    {
        double solution = -b / (2 * a);
        return { solution, INFINITY };
    }
    else if (delta > 0)
    {
        double sqrt_delta = sqrt(delta);
        double solution1 = (-b + sqrt_delta) / 2 * a;
        double solution2 = (-b - sqrt_delta) / 2 * a;

        return { solution1, solution2 };
    }
    else
    {
        invalid:
            return { INFINITY, INFINITY };
    }
}

void solve()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    auto solutions = find_quadratic_function_solution(a, b, c);

    if (solutions.first == INFINITY && solutions.second == INFINITY)
    {
        printf("no solutions!\n");
    }
    else
    {
        if (solutions.first != INFINITY)
        {
            printf("solution 1: %f\n", solutions.first);
        }
        if (solutions.second != INFINITY)
        {
            printf("solution 2: %f\n", solutions.second);
        }
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif