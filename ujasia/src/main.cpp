#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
using namespace std;

void print_candles(bool *candles, uint32_t age)
{
    for (uint32_t i = 1; i <= age; i++)
    {
        printf("%d ", candles[i]);
    }
    printf("\n");
}

uint32_t candles_left(bool *candles, uint32_t age)
{
    uint32_t result = 0;

    for (uint32_t i = 1; i <= age; i++)
    {
        result += candles[i];
    }

    return result;
}

uint32_t get_first_lighted_candle(bool *candles, uint32_t age)
{
    for (uint32_t i = 1; i <= age; i++)
    {
        if (candles[i]) return i;
    }
    return 0;
}

uint32_t get_last_candle(uint32_t age)
{
    bool *candles = (bool *) calloc(age + 2, 1);
    memset(candles + 1, true, age);

    bool put_out_candle = false;
    while (candles_left(candles, age) > 1)
    {
        // bool put_out_candle = false;
        for (uint32_t i = 1; i <= age; i++)
        {
            if (!candles[i]) continue;
            else if (put_out_candle)
            {
                candles[i] = 0;
            }
            put_out_candle = !put_out_candle;
        }

        // print_candles(candles, age);
    }

    uint32_t last_candle = get_first_lighted_candle(candles, age);
    free(candles);

    return last_candle;
}

void solve()
{
    uint32_t queries;
    scanf("%d", &queries);

    for (uint32_t i = 0; i < queries; i++)
    {
        uint32_t age;
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