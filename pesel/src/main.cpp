#include <stdio.h>
using namespace std;

#include "Pesel.h"

void solve()
{
    char *buf = (char *) malloc(64);
    printf("Enter PESEL: ");
    scanf("%s", buf);

    try
    {
        Pesel pesel = Pesel(buf);

        char *str = pesel.to_string();
        printf
        (
            "PESEL: %s\n",
            str
        );
        free(str);

        printf
        (
            "Gender: %s\n",
            Gender_enum_to_string(pesel.get_gender())
        );

        printf
        (
            "Date of birth (year): %i\n",
            pesel.get_birth_year()
        );

        printf
        (
            "Date of birth (month): %s\n",
            Month_enum_to_string(pesel.get_birth_month())
        );

        printf
        (
            "Date of birth (day): %i\n",
            pesel.get_birth_day()
        );

        char *date = pesel.get_birth_date();
        printf
        (
            "Date of birth (date): %s\n",
            date
        );
        free(date);

        printf
        (
            "Valid: %s\n",
            pesel.verify_validity() ? "Yes" : "No"
        );
    }
    catch (const exception& e)
    {
        printf("[ERROR] %s\n", e.what());
    }

    free(buf);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif