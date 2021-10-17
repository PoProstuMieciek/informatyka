#include <stdio.h>
#include <fstream>
using namespace std;

size_t load_numbers_from_file(const char* filename, int *numbers)
{
    size_t numbers_written = 0;

    ifstream file(filename);
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> numbers[numbers_written++];
        }
    }
    numbers[numbers_written] = 0;
    return numbers_written - 1;
}

int sum_of_digits(int number)
{
    int result = 0;
    while (number != 0)
    {
        result += number % 10;
        number /= 10;
    }
    return result;
}

bool digits_in_order(int number)
{
    char last_digit, curr_digit;
    while (number != 0)
    {
        last_digit = number % 10;
        number /= 10;
        curr_digit = number % 10;

        if (!(curr_digit < last_digit)) return false;
    }
    return true;
}

int count_even_numbers(const int *numbers, size_t size)
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (numbers[i] % 2 == 0) count++;
    }
    return count;
}

int get_highest_sum_of_digits(int *numbers, size_t size)
{
    int last_highest_val = -1;
    int last_higest_idx = 0;

    for (size_t i = 0; i < size; i++)
    {
        int current_sum = sum_of_digits(numbers[i]);
        if (current_sum > last_highest_val)
        {
            last_highest_val = current_sum;
            last_higest_idx = i;
        }
    }

    return numbers[last_higest_idx];
}

int get_lowest_sum_of_digits(int *numbers, size_t size)
{
    int last_lowest_val = 1e9;
    int last_lowest_idx = 0;

    for (size_t i = 0; i < size; i++)
    {
        int current_sum = sum_of_digits(numbers[i]);
        if (current_sum < last_lowest_val)
        {
            last_lowest_val = current_sum;
            last_lowest_idx = i;
        }
    }

    return numbers[last_lowest_idx];
}

size_t get_numbers_digits_in_order(const int *numbers, size_t size, int *output)
{
    size_t numbers_written = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (digits_in_order(numbers[i]))
        {
            output[numbers_written++] = numbers[i];
        }
    }
    return numbers_written - 1;
}

void solve()
{
    int *numbers = (int *) malloc((1000 + 1) * sizeof(int));
    size_t numbers_size = load_numbers_from_file("test/numbers.in", numbers);

    printf(
        "a) %d\n",
        count_even_numbers(numbers, numbers_size)
    );

    printf(
        "b) %d %d\n",
        get_highest_sum_of_digits(numbers, numbers_size),
        get_lowest_sum_of_digits(numbers, numbers_size)
    );

    printf("c) ");
    int *numbers_digits_in_order = (int *) malloc((1000 + 1) * sizeof(int));
    size_t size = get_numbers_digits_in_order(numbers, numbers_size, numbers_digits_in_order);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", numbers_digits_in_order[i]);
    }
    printf("\n");
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif