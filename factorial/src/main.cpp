#include <stdio.h>

long long factorial(int x)
{
    long long output = 1;
    for (int i = 1; i <= x; i++)
    {
        output *= i;
    }
    return output;
}

int main()
{
    int x;
    scanf("%i", &x);
    printf("%lli\n", factorial(x));
}