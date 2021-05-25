#include <stdio.h>

long long nth_triangle_number(int x)
{
    long long output = 0;
    for (int i = 1; i <= x; i++)
    {
        output += i;
    }
    return output;
}

int main()
{
    int x;
    scanf("%i", &x);
    printf("%lli\n", nth_triangle_number(x));
}