#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int y[10] = { 0 };

    memcpy(y, x, sizeof(x));
    reverse(y, y + sizeof(x) / sizeof(int));

    for (auto i = 0; i < 10; i++)
    {
        printf("%i ", y[i]);
    }
    printf("\n");
}