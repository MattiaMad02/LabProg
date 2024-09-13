//
// Created by eugen on 13/09/2024.
//
#include "gtest/gtest.h"
#include "../Date.h"
#include <fstream>

TEST(DateTest, ValidDate) {
    Date date(15, 9, 2023);
    EXPECT_EQ(date.getDay(), 15);
    EXPECT_EQ(date.getMonth(), 9);
    EXPECT_EQ(date.getYear(), 2023);
}

TEST(DateTest, InvalidDate) {
    EXPECT_THROW(Date date(32, 1, 2023), Date::DateException);  // Giorno non valido
    EXPECT_THROW(Date date(15, 13, 2023), Date::DateException); // Mese non valido
    EXPECT_THROW(Date date(29, 2, 2021), Date::DateException);  // Non bisestile
}

TEST(DateTest, LeapYear) {
    Date leapDate(29, 2, 2020);
    EXPECT_EQ(leapDate.getDay(), 29);
    EXPECT_EQ(leapDate.getMonth(), 2);
    EXPECT_EQ(leapDate.getYear(), 2020);

    EXPECT_THROW(Date invalidLeapDate(29, 2, 2019),Date::DateException);
}

TEST(DateTest, DaysInMonth) {
    Date date(1, 2, 2023);
    EXPECT_EQ(date.daysInMonth(), 28);

    Date leapYearDate(1, 2, 2020);
    EXPECT_EQ(leapYearDate.daysInMonth(), 29);

    Date marchDate(1, 3, 2023);
    EXPECT_EQ(marchDate.daysInMonth(), 31);
}

TEST(DateTest, EqualityOperator) {
    Date date1(15, 9, 2023);
    Date date2(15, 9, 2023);
    Date date3(16, 9, 2023);

    EXPECT_TRUE(date1 == date2);
    EXPECT_FALSE(date1 == date3);
}
