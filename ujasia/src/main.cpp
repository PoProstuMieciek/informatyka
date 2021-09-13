#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
using namespace std;

uint64_t highest_power_of_2(uint64_t n)
{
    uint64_t result = 1;
    while (result <= n)
    {
        result <<= 1;
    }
    result >>= 1;
    return result;
}

int get_last_candle(int age)
{
    uint64_t h_pow2 = highest_power_of_2(age);

    return 2 * (age - h_pow2) + 1;
}

void solve()
{
    int queries;
    scanf("%d", &queries);

    for (int i = 0; i < queries; i++)
    {
        int age;
        scanf("%d", &age);

        printf("%d\n", get_last_candle(age));
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif