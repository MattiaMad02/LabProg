//
// Created by eugen on 13/09/2024.
//
#include "gtest/gtest.h"
#include "../Date.h"
#include <fstream>
TEST(DateTest, ConstructorValid) {
    Date d(15, 8, 2023);
    EXPECT_EQ(d.getDay(), 15);
    EXPECT_EQ(d.getMonth(), 8);
    EXPECT_EQ(d.getYear(), 2023);
}

TEST(DateTest, ConstructorInvalid) {
    EXPECT_THROW(Date d(32, 1, 2023), Date::DateException);
    EXPECT_THROW(Date d(15, 13, 2023), Date::DateException);
}
TEST(DateTest, GetMethods) {
    Date d(15, 8, 2023);
    EXPECT_EQ(d.getDay(), 15);
    EXPECT_EQ(d.getMonth(), 8);
    EXPECT_EQ(d.getYear(), 2023);
}


TEST(DateTest, SetMethodsValid) {
    Date d(15, 8, 2023);
    d.setDay(20);
    EXPECT_EQ(d.getDay(), 20);
    d.setMonth(12);
    EXPECT_EQ(d.getMonth(), 12);
    d.setYear(2024);
    EXPECT_EQ(d.getYear(), 2024);
}
TEST(DateTest, SetMethodsInvalid) {
    Date d(15, 8, 2023);
    EXPECT_THROW(d.setDay(32), Date::DateException);
    EXPECT_THROW(d.setMonth(13), Date::DateException);
    EXPECT_THROW(d.setYear(-1), Date::DateException);
}


TEST(DateTest, IsLeapYear) {
    Date d1(15, 8, 2020);
    EXPECT_TRUE(d1.isLeapYear());
    Date d2(15, 8, 2021);
    EXPECT_FALSE(d2.isLeapYear());
}
TEST(DateTest, DaysInMonth) {
    Date d1(15, 2, 2020); // Leap year
    EXPECT_EQ(d1.daysInMonth(), 29);
    Date d2(15, 2, 2021); // Non-leap year
    EXPECT_EQ(d2.daysInMonth(), 28);
    Date d3(15, 4, 2021);
    EXPECT_EQ(d3.daysInMonth(), 30);
    Date d4(15, 1, 2021);
    EXPECT_EQ(d4.daysInMonth(), 31);
}
TEST(DateTest, PrintMethod) {
    Date d(15, 8, 2023);
    testing::internal::CaptureStdout();
    d.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "15/08/2023\n");
}


TEST(DateTest, EqualityOperator) {
    Date d1(15, 8, 2023);
    Date d2(15, 8, 2023);
    Date d3(16, 8, 2023);
    EXPECT_TRUE(d1 == d2);
    EXPECT_FALSE(d1 == d3);
}