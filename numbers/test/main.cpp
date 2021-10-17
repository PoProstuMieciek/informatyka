#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

int *numbers, *numbers_simple;
size_t numbers_size = 0, numbers_simple_size = 0;

TEST(before_all_tests, load_numbers_from_file)
{
    numbers = (int *) malloc((1000 + 1) * sizeof(int));
    numbers_size = load_numbers_from_file("test/numbers.in", numbers);
    ASSERT_EQ(1000, numbers_size);

    numbers_simple = (int *) malloc((1000 + 1) * sizeof(int));
    numbers_simple_size = load_numbers_from_file("test/numbers_simple.in", numbers_simple);
    ASSERT_EQ(4, numbers_simple_size);
}

TEST(examples, sum_of_digits)
{
    EXPECT_EQ(12, sum_of_digits(66));
    EXPECT_EQ(5, sum_of_digits(122));
    EXPECT_EQ(3, sum_of_digits(30000000));
    EXPECT_EQ(1, sum_of_digits(100));
    EXPECT_EQ(15, sum_of_digits(1111119));
    EXPECT_EQ(25, sum_of_digits(66562));
    EXPECT_EQ(13, sum_of_digits(121324));
}

TEST(examples, digits_in_order)
{
    EXPECT_EQ(true, digits_in_order(123));
    EXPECT_EQ(true, digits_in_order(123579));
    EXPECT_EQ(false, digits_in_order(1232));
    EXPECT_EQ(false, digits_in_order(34556));
}

TEST(numbers_simple, count_even_numbers)
{
    EXPECT_EQ(4, count_even_numbers(numbers_simple, numbers_simple_size));
}

TEST(numbers_simple, get_lowest_sum_of_digits)
{
    int lowest_sum = get_lowest_sum_of_digits(numbers_simple, numbers_simple_size);
    EXPECT_EQ(121324, lowest_sum);
}

TEST(numbers_simple, get_highest_sum_of_digits)
{
    int highest_sum = get_highest_sum_of_digits(numbers_simple, numbers_simple_size);
    EXPECT_EQ(66562, highest_sum);
}

TEST(numbers, get_lowest_sum_of_digits)
{
    int lowest_sum = get_lowest_sum_of_digits(numbers, numbers_size);
    EXPECT_EQ(10010, lowest_sum);
}

TEST(numbers, get_highest_sum_of_digits)
{
    int highest_sum = get_highest_sum_of_digits(numbers, numbers_size);
    EXPECT_EQ(187869866, highest_sum);
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}