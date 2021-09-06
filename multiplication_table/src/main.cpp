#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

#define COLOR_RESET   "\x1b[0m"
#define COLOR_BOLD   "\x1b[1m"

#define COLOR_BLACK   "\x1b[30m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_WHITE   "\x1b[37m"

#define COLOR_LIGHT_BLACK   "\x1b[30;1m"
#define COLOR_LIGHT_RED     "\x1b[31;1m"
#define COLOR_LIGHT_GREEN   "\x1b[32;1m"
#define COLOR_LIGHT_YELLOW  "\x1b[33;1m"
#define COLOR_LIGHT_BLUE    "\x1b[34;1m"
#define COLOR_LIGHT_MAGENTA "\x1b[35;1m"
#define COLOR_LIGHT_CYAN    "\x1b[36;1m"
#define COLOR_LIGHT_WHITE   "\x1b[37;1m"

using namespace std;

size_t number_length(int n)
{
    int count = 0;
    do
    {
        count++;
        n /= 10;
    }
    while (n != 0);

    return count;
}

int print_times(int n, const char c)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
    return n;
}

void print_multiplication_table(size_t width = 10, size_t height = 10)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printf("[DEBUG] width=%d, height=%d\n", w.ws_col, w.ws_row);

    long long maximum = width * height;
    size_t spacing = number_length(maximum);

    if ((spacing + 4) * width >= w.ws_col)
    {
        printf("[ERROR] Table would not fit on your screen!\n");
        return;
    }

    // header
    printf(COLOR_GREEN "");
    size_t table_width = 0;
    table_width += printf("|");
    table_width += print_times(spacing + 2, ' ');
    for (size_t i = 1; i <= width; i++)
    {
        int spacing_before = spacing - number_length(i) + 1;
        size_t iter_width = 0;
        iter_width += printf("|");
        iter_width += print_times(spacing_before, ' ');
        printf(COLOR_RED "");
        iter_width += printf("%lu ", i);
        printf(COLOR_GREEN "");
        table_width += iter_width;
    }
    printf("|\n"); table_width++;

    // separating line
    print_times(table_width, '-');
    printf("\n" COLOR_RESET);

    // rows
    for (size_t i = 1; i <= height; i++)
    {
        int spacing_before = spacing - number_length(i) + 1;
        printf(COLOR_GREEN "|");
        print_times(spacing_before, ' ');
        printf(COLOR_RED "%lu" COLOR_GREEN " |" COLOR_RESET, i);

        for (size_t j = 1; j <= width; j++)
        {
            int result = i * j;
            int spacing_before = spacing - number_length(result) + 1;
            print_times(spacing_before, ' ');
            printf(COLOR_CYAN "%d " COLOR_GREEN "|" COLOR_RESET, result);
        }
        printf("\n");
    }

    // separating line
    printf(COLOR_GREEN "");
    print_times(table_width, '-');
    printf("\n" COLOR_RESET);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    size_t width, height;
    scanf("%lu %lu", &width, &height);

    print_multiplication_table(width, height);
    printf("\n");
}
#endif