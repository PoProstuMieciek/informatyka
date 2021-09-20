#pragma once

enum Gender
{
    Male,
    Female
};

extern const char *Gender_strings[];

const char *Gender_enum_to_string(Gender input);