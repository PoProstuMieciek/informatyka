#include <stdio.h>
#include <string>
using namespace std;

string dec_to_bin(uint64_t dec)
{
    if (dec <= 1)
    {
        return (dec % 2) ? "1" : "0";
    }
    else
    {
        // these mean the same and are *probably* optimized to the same assembly instruction
        // return dec_to_bin(dec / 2) + dec_to_bin(dec % 2);
        return dec_to_bin(dec >> 1) + dec_to_bin(dec & 1);
    }
}

void solve()
{
    for (uint64_t i = 0; i <= 1 << 6; i++)
    {
        printf("%li\t%9s\n", i, dec_to_bin(i).c_str());
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif