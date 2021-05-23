#include <stdio.h>
using namespace std;

int main()
{
    int N;
    scanf("%i", &N);

    printf("%i %i\n", N, 2*N+1);

    for (int i = 0; i < N; i++)
    {
        printf("%i %i %i\n", i, 2*i+1, 2*i+2);
    }
}