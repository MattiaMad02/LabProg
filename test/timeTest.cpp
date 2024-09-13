//
// Created by eugen on 13/09/2024.
//
#include "gtest/gtest.h"
#include "../Time.h"
#include <fstream>
TEST(TimeTest, ConstructorValid) {
    Time t(10, 30);
    EXPECT_EQ(t.getOra(), 10);
    EXPECT_EQ(t.getMinuti(), 30);
}

TEST(TimeTest, ConstructorInvalid) {
    EXPECT_THROW(Time t(25, 30),Time::TimeException);
    EXPECT_THROW(Time t(10, 61),Time::TimeException);
}

TEST(TimeTest, GetMethods) {
    Time t(10, 30);
    EXPECT_EQ(t.getOra(), 10);
    EXPECT_EQ(t.getMinuti(), 30);
}
TEST(TimeTest, SetMethodsValid) {
    Time t(10, 30);
    t.setOra(12);
    EXPECT_EQ(t.getOra(), 12);
    t.setMinuti(45);
    EXPECT_EQ(t.getMinuti(), 45);
}

TEST(TimeTest, SetMethodsInvalid) {
    Time t(10, 30);
    EXPECT_THROW(t.setOra(25),Time::TimeException);
    EXPECT_THROW(t.setMinuti(61),Time::TimeException);
}
TEST(TimeTest, PrintMethod) {
    Time t(10, 30);
    testing::internal::CaptureStdout();
    t.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10:30\n");
}

