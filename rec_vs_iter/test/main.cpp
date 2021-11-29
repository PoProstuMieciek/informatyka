#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
#include <random>
using namespace std;
using namespace testing;

TEST(D, example)
{
    ASSERT_EQ(11, D_recursive(31));
    ASSERT_EQ(11, D_iterative(31));
}

TEST(D, random)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1e5);

    for (size_t i = 0; i < 1e3; i++)
    {
        int v = distrib(gen);
        ASSERT_EQ(D_recursive(v), D_iterative(v));
    }
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}