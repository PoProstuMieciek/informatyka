#include <stdio.h>
#include <stdlib.h>
using namespace std;

double sum(double *array, size_t size)
{
    double result = 0;
    for (size_t i = 0; i < size; i++)
    {
        result += array[i];
    }
    return result;
}

double average(double *array, size_t size)
{
    double array_sum = sum(array, size);
    double average = array_sum / size;
    return average;
}

void solve()
{
    size_t grades_length;
    scanf("%lu", &grades_length);

    double *grades = (double *) calloc(grades_length + 1, sizeof(double));

    for (size_t i = 0; i < grades_length; i++)
    {
        scanf("%lf", &grades[i]);
    }

    double grades_average = average(grades, grades_length);
    printf("%lf\n", grades_average);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif