//
// Created by eugen on 21/07/2024.
//
#include "gtest/gtest.h"
#include "../Activity.h"
#include <fstream>

TEST(ActivityTest, ConstructorAndGetters) {
    Activity activity("Palestra", Date(1, 1, 2024), Time(10, 0), false);

    EXPECT_EQ(activity.getDescription(), "Palestra");
    EXPECT_EQ(activity.getData(), Date(1, 1, 2024));
    EXPECT_EQ(activity.getTime(), Time(10, 0));
    EXPECT_FALSE(activity.isCompleted());
}

TEST(ActivityTest, Setters) {
    Activity activity("Palestra", Date(1, 1, 2024), Time(10, 0), false);

    activity.setDescription("Dottore");
    activity.setData(Date(2, 2, 2024));
    activity.setTime(Time(8, 30));
    activity.setCompleted(true);

    EXPECT_EQ(activity.getDescription(), "Dottore");
    EXPECT_EQ(activity.getData(), Date(2, 2, 2024));
    EXPECT_EQ(activity.getTime(), Time(8, 30));
    EXPECT_TRUE(activity.isCompleted());
}

TEST(ActivityTest, DoneActivity) {
    Activity activity("Corsa", Date(1, 1, 2024), Time(7, 0), false);
    activity.doneActivity();

    EXPECT_TRUE(activity.isCompleted());
}

TEST(ActivityTest, SaveAndLoadFromFile) {// Creazione di un'attività e salvataggio su file
    Activity activityOut("Sessione di studio", Date(5, 3, 2023), Time(14, 30), false);
    std::ofstream outFile("activity.txt");
    activityOut.saveToFile(outFile);
    outFile.close();

    Activity activityIn("Default Activity"); // Passa una descrizione non vuota
    std::ifstream inFile("activity.txt");
    activityIn.loadFromFile(inFile);
    inFile.close();

    EXPECT_EQ(activityIn.getDescription(), "Sessione di studio");
    EXPECT_EQ(activityIn.getData(), Date(5, 3, 2023));
    EXPECT_EQ(activityIn.getTime(), Time(14, 30));
    EXPECT_FALSE(activityIn.isCompleted());
}

TEST(ActivityTest, EmptyDescriptionException) {
    EXPECT_THROW(Activity activity("", Date(1, 1, 2024), Time(10, 0), false), Activity::ActivityException);
}

TEST(ActivityTest, LoadInvalidFileException) {
    std::ofstream outFile("invalid_activity.txt");
    outFile << "\n";
    outFile.close();

    Activity activity("Default Activity");
    std::ifstream inFile("invalid_activity.txt");

    EXPECT_THROW(activity.loadFromFile(inFile), Activity::ActivityException);
}
TEST(ActivityTest, EqualityOperator) {
    Date date1(5, 3, 2023);
    Time time1(14, 30);
    Activity activity1("Sessione di studio", date1, time1, false);
    Activity activity2("Sessione di studio", date1, time1, false);

    EXPECT_TRUE(activity1 == activity2);

    Date date2(6, 4, 2023);
    Time time2(15, 45);
    Activity activity3("Palestra", date2, time2, true);

    EXPECT_FALSE(activity1 == activity3);
}