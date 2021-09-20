#define GTEST_DECLARES_MAIN

#include "../src/Pesel.h"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(Pesel, 05271706552)
{
    Pesel pesel = Pesel("05271706552");

    ASSERT_STREQ("05271706552", pesel.to_string());

    ASSERT_EQ(Male, pesel.get_gender());

    ASSERT_EQ(17, pesel.get_birth_day());
    ASSERT_EQ(July, pesel.get_birth_month());
    ASSERT_EQ(2005, pesel.get_birth_year());

    char *date = pesel.get_birth_date();
    ASSERT_STREQ("17.07.2005", date);
    free(date);

    ASSERT_EQ(true, pesel.verify_validity());
}

TEST(Pesel, 05271706559)
{
    Pesel pesel = Pesel("05271706559");

    ASSERT_STREQ("05271706559", pesel.to_string());

    ASSERT_EQ(Male, pesel.get_gender());

    ASSERT_EQ(17, pesel.get_birth_day());
    ASSERT_EQ(July, pesel.get_birth_month());
    ASSERT_EQ(2005, pesel.get_birth_year());

    char *date = pesel.get_birth_date();
    ASSERT_STREQ("17.07.2005", date);
    free(date);

    ASSERT_EQ(false, pesel.verify_validity());
}

TEST(Pesel, 55030101193)
{
    Pesel pesel = Pesel("55030101193");

    ASSERT_STREQ("55030101193", pesel.to_string());

    ASSERT_EQ(Male, pesel.get_gender());

    ASSERT_EQ(1, pesel.get_birth_day());
    ASSERT_EQ(March, pesel.get_birth_month());
    ASSERT_EQ(1955, pesel.get_birth_year());

    char *date = pesel.get_birth_date();
    ASSERT_STREQ("01.03.1955", date);
    free(date);

    ASSERT_EQ(true, pesel.verify_validity());
}

TEST(Pesel, 55030101230)
{
    Pesel pesel = Pesel("55030101230");

    ASSERT_STREQ("55030101230", pesel.to_string());

    ASSERT_EQ(Male, pesel.get_gender());

    ASSERT_EQ(1, pesel.get_birth_day());
    ASSERT_EQ(March, pesel.get_birth_month());
    ASSERT_EQ(1955, pesel.get_birth_year());

    char *date = pesel.get_birth_date();
    ASSERT_STREQ("01.03.1955", date);
    free(date);

    ASSERT_EQ(true, pesel.verify_validity());
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}