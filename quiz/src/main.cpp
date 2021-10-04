#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const char *questions[] = {
    "What is the result of the following operation:\n    2 + 2 = ? [number]",
    "What is the result of the following equation:\n    2x = 10, x = ? [number]",
    "What is the result of the following equation:\n    5x + 10 = 65, x = ? [number]",
    "Do you think your answer is correct? [yes/no]",
    "How many dm^3 are there in 1 m^3 ? [number]",
    "Fill the gaps in the sentence:\n    Linus ... is the creator and maintainer of Linux kernel. [string]",
    "Fill the gaps in the sentence:\n    MongoDB is an open-source, cross-platform ... oriented database system. [document/table]",
    "Fill the gaps in the sentence:\n    Redis is an in-memory ... database [key-value/relational]",
    "Fill the gaps in the sentence:\n    C programming language was designed by ... Ritchie. [string]",
    "Fill the gaps in the sentence:\n    ... is the worst programming language ever created! [string]",
    0
};

const char *expected_output[] = {
    "4",
    "5",
    "11",
    "yes",
    "1000",
    "Torvalds",
    "document",
    "key-value",
    "Dennis",
    "Python",
    0
};

void solve()
{
    int points = 0;
    int question_index = 0;
    while (questions[question_index] && expected_output[question_index])
    {
        printf("%s\n", questions[question_index]);

        char *buf = (char *) malloc(64);
        scanf("%s", buf);

        if (strcasecmp(buf, expected_output[question_index]) == 0)
        {
            printf("Correct!\n");
            points += 10;
        }
        else
        {
            printf("Answer '%s' is incorrect! Correct answer: '%s'\n", buf, expected_output[question_index]);
        }

        printf("\n");

        question_index++;
    }

    printf("\nYour score: %d\n", points);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif