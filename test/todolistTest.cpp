//
// Created by eugen on 21/07/2024.
//
#include "gtest/gtest.h"
#include "../TodoList.h"

TEST(TodoList, AddActivity) {
TodoList todoList;
Activity activity("Test Activity", Date(1, 1, 2023), Time(10, 0), false);
todoList.addActivity(activity);

EXPECT_EQ(todoList.NumberActivitiestoDo(), 1);
}

TEST(TodoList, RemoveCompletedActivities) {
TodoList todoList;
Activity activity("Test Activity", Date(1, 1, 2023), Time(10, 0), true);
todoList.addActivity(activity);
todoList.removeActivityCompleted();

EXPECT_EQ(todoList.NumberActivitiestoDo(), 0);
}