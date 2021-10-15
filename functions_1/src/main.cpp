#include <stdio.h>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());

int nth_triangle_number(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

double calc(int x, int y)
{
    double numerator = factorial(x) + factorial(y);
    double denominator = nth_triangle_number(y);
    return numerator / denominator;
}

void solve()
{
    uniform_int_distribution<> distr(5, 10);

    int x = distr(gen);
    int y;

    do scanf("%d", &y);
    while (!(y > 0));

    printf("%f\n", calc(x, y));
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif