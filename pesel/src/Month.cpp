#include "Month.h"

const char *Month_strings[] = 
{
    0,
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const char *Month_enum_to_string(Month input) { return Month_strings[input]; }