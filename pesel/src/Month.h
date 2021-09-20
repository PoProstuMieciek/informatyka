#pragma once

enum Month
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

extern const char *Month_strings[];

const char *Month_enum_to_string(Month input);