#include "Pesel.h"

Pesel::Pesel(const char *input)
{
    data = (char *) malloc(11 * sizeof(char));

    parse(input);
}

Pesel::~Pesel()
{
    free(data);
}

void Pesel::parse(const char *input)
{
    size_t input_size = strlen(input);

    if (input_size != 11) throw length_error("given input should be 11 characters long");

    for (int i = 0; i < 11; i++)
    {
        if ('0' <= input[i] && input[i] <= '9')
        {
            data[i] = input[i] - '0';
        }
        else throw invalid_argument("given input should be only digits");
    }
}

char *Pesel::to_string()
{
    char *buf = (char *) malloc(12 * sizeof(char));

    int i;
    for (i = 0; i < 11; i++)
    {
        buf[i] = data[i] + '0';
    }
    buf[i] = 0;

    return buf;
}

Gender Pesel::get_gender()
{
    if (data[9] % 2 == 0) return Female;
    else return Male;
}

char *Pesel::get_birth_date()
{
    char *buf = (char *) malloc(32 * sizeof(char));

    int day = get_birth_day();
    int month = get_birth_month();
    int year = get_birth_year();

    sprintf(buf, "%.2i.%.2i.%.4i", day, month, year);

    return buf;
}

int Pesel::get_birth_year()
{
    int year_mod = -1;
    int year  = 10 * data[0] + data[1];
    int month_mod = -1;
    int month = 10 * data[2] + data[3];

    if (81 <= month && month <= 92) { month_mod = -80; year_mod = 1800; }
    if (1  <= month && month <= 12) { month_mod = 0; year_mod = 1900; }
    if (21 <= month && month <= 32) { month_mod = -20; year_mod = 2000; }
    if (41 <= month && month <= 52) { month_mod = -40; year_mod = 2100; }
    if (61 <= month && month <= 72) { month_mod = -60; year_mod = 2200; }

    if (year_mod == -1 || month_mod == -1) throw invalid_argument("month is invalid");

    year += year_mod;
    month += month_mod;

    return year;
}

Month Pesel::get_birth_month()
{
    int year_mod = -1;
    int year  = 10 * data[0] + data[1];
    int month_mod = -1;
    int month = 10 * data[2] + data[3];

    if (81 <= month && month <= 92) { month_mod = -80; year_mod = 1800; }
    if (1  <= month && month <= 12) { month_mod = 0; year_mod = 1900; }
    if (21 <= month && month <= 32) { month_mod = -20; year_mod = 2000; }
    if (41 <= month && month <= 52) { month_mod = -40; year_mod = 2100; }
    if (61 <= month && month <= 72) { month_mod = -60; year_mod = 2200; }

    if (year_mod == -1 || month_mod == -1) throw invalid_argument("month is invalid");

    year += year_mod;
    month += month_mod;

    return (Month) month;
}

char Pesel::get_birth_day()
{
    char day = 10 * data[4] + data[5];
    return day;
}

bool Pesel::verify_validity()
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += data[i] * weights[i];
    }
    int modulo = sum % 10;

    int checksum;
    if (modulo == 0) checksum = 0;
    else checksum = 10 - modulo;

    return data[10] == checksum;
}