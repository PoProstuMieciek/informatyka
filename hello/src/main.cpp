#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);

    for (int i = n; i > 0; i--)
    {
        printf("%i. Hello\n", i);
    }
}