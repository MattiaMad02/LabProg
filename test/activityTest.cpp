//
// Created by eugen on 21/07/2024.
//
#include "gtest/gtest.h"
#include "../Activity.h"

TEST(Activity, createActivity){
    Date date(1, 1, 2023);
Time time(10, 0);
Activity activity("Test Activity", date, time, false);

EXPECT_EQ(activity.getDescription(), "Test Activity");
EXPECT_EQ(activity.getData().getDay(), 1);
EXPECT_EQ(activity.getTime().getOra(), 10);
EXPECT_FALSE(activity.isCompleted());
}

