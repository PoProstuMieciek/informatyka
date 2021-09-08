#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(average, random)
{
    double grades[] = { 1, 2, 6, 4, 2, 4, 5, 3, 2, 3, 5, 5, 4, 5, 6 };
    ASSERT_EQ(3.8, average(grades, 15));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}