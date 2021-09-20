#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdexcept>
using namespace std;

#include "Gender.h"
#include "Month.h"

class Pesel
{
    private:
        char *data;
        const char weights[11] = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1 };

        void parse(const char *input);

    public:
        Pesel(const char *input);
        ~Pesel();

        char *to_string();

        Gender get_gender();

        char *get_birth_date();

        int get_birth_year();
        Month get_birth_month();
        char get_birth_day();

        bool verify_validity();
};