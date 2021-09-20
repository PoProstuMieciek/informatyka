#include "Gender.h"

const char *Gender_strings[] = 
{
    "Male",
    "Female"
};

const char *Gender_enum_to_string(Gender input) { return Gender_strings[input]; }