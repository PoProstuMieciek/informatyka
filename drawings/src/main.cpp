#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char *repeat_char(const char c, size_t times)
{
    char *buf = (char *) malloc(times + 1);

    for (size_t i = 0; i < times; i++)
    {
        buf[i] = c;
    }
    buf[times] = 0;

    return buf;
}

char *center_text(const char *text, size_t desired_width)
{
    size_t size = strlen(text);

    if (size > desired_width) return nullptr;
    else
    {
        size_t spacing_one_side_size = (desired_width - size) / 2;
        char *spacing_one_side = repeat_char(' ', spacing_one_side_size);

        char *buf = (char *) malloc(desired_width + 1);
        sprintf(buf, "%s%s%s", spacing_one_side, text, spacing_one_side);
        free(spacing_one_side);
        return buf;
    }
}

long long nth_triangle_number(int x)
{
    long long output = 0;
    for (int i = 1; i <= x; i++)
    {
        output += i;
    }
    return output;
}

char *triangle_1(size_t n)
{
    char *buf = (char *) malloc(nth_triangle_number(n + 1) + 1);
    buf[0] = 0;

    for (size_t i = n; i >= 1; i--)
    {
        char *line = repeat_char('*', i);
        sprintf(buf + strlen(buf), "%s\n", line);

        free(line);
    }

    return buf;
}

char *triangle_2(size_t n)
{
    char *buf = (char *) malloc((n * (n + 1)) + 1);
    buf[0] = 0;

    for (size_t i = n; i >= 1; i--)
    {
        char *before = repeat_char(' ', n - i);
        char *line = repeat_char('*', i);
        sprintf(buf + strlen(buf), "%s%s\n", before, line);

        free(before);
        free(line);
    }

    return buf;
}

char *triangle_3(size_t n)
{
    char *buf = (char *) malloc(nth_triangle_number(n + 1) + 1);
    buf[0] = 0;

    for (size_t i = 1; i <= n; i++)
    {
        char *line = repeat_char('*', i);
        sprintf(buf + strlen(buf), "%s\n", line);

        free(line);
    }

    return buf;
}

char *triangle_4(size_t n)
{
    char *buf = (char *) malloc((n * (n + 1)) + 1);
    buf[0] = 0;

    for (size_t i = 1; i <= n; i++)
    {
        char *before = repeat_char(' ', n - i);
        char *line = repeat_char('*', i);
        sprintf(buf + strlen(buf), "%s%s\n", before, line);

        free(before);
        free(line);
    }

    return buf;
}

char *square(size_t n)
{
    // TODO: !!!

    char *buf = (char *) malloc(1);
    buf[0] = 0;
    return buf;
}

char *tree(size_t n)
{
    // size_t max_size = 2 * (n - 1) + 1;
    size_t max_size = 2 * n - 1;

    char *buf = (char *) malloc(((max_size + 1) * (n + 1)) + 1);
    buf[0] = 0;

    for (size_t s = 1; s <= max_size; s += 2)
    {
        char *line = repeat_char('*', s);
        char *centered = center_text(line, max_size);
        if (!centered) return nullptr;

        sprintf(buf + strlen(buf), "%s\n", centered);
        free(line);
        free(centered);
    }

    char *bottom = center_text("*", max_size);
    sprintf(buf + strlen(buf), "%s\n", bottom);
    free(bottom);

    return buf;
}

char *loop(size_t n)
{
    // TODO: !!!

    char *buf = (char *) malloc(1);
    buf[0] = 0;
    return buf;
}

void solve()
{
    size_t n;
    scanf("%lu", &n);

    if (n == 0) return;

    char *t1 = triangle_1(n);
    char *t2 = triangle_2(n);
    char *t3 = triangle_3(n);
    char *t4 = triangle_4(n);
    char *sq = square(n);
    char *tr = tree(n);
    char *lp = loop(n);

    printf("%s\n", t1);
    printf("%s\n", t2);
    printf("%s\n", t3);
    printf("%s\n", t4);
    printf("%s\n", sq);
    printf("%s\n", tr);
    printf("%s\n", lp);

    free(t1);
    free(t2);
    free(t3);
    free(t4);
    free(sq);
    free(tr);
    free(lp);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif