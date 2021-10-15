#include <stdio.h>
#include <stdarg.h>
#include <math.h>
using namespace std;

const bool DEBUG = true;
int a, b, n;

int debug(const char *format, ...)
{
    if (!DEBUG) return 0;

    va_list args;
    va_start(args, format);
    auto ret = vprintf(format, args);
    va_end(args);
    return ret;
}

void subproblem_a()
{
    debug("a)\n");

    do scanf("%d", &a);
    while (!(a > 0));

    do scanf("%d", &b);
    while (!(b > 0));

    do scanf("%d", &n);
    while (!(n > 0));
}

double subproblem_b(int n = n)
{
    debug("b)\n");

    double result = 0;
    int denominator = 1;
    for (int i = 0; i < n; i++)
    {
        double number = -5.0f / denominator;
        debug("result: %f\tdenominator: %lld\tnumber: %f\n", result, denominator, number);
        result += number;
        denominator <<= 1;
    }
    return result;
}

bool subproblem_c(int a = a, int b = b)
{
    debug("c)\n");
    return (2 * a - b) > 0;
}

double subproblem_d(int n = n)
{
    debug("d)\n");
    double sum = 0;
    double number = 0.3f;
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        sum += number * sign;
        number *= 2;
        sign *= -1;
    }
    return sum;
}

double subproblem_e(int x = a, int n = n)
{
    debug("e)\n");
    return pow(1 + x, n);
}

void solve()
{
    subproblem_a();
    printf("\n");
    printf("%f\n\n", subproblem_b());
    printf("%s\n\n", subproblem_c() ? "true" : "false");
    printf("%f\n\n", subproblem_d());
    printf("%f\n\n", subproblem_e());
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif