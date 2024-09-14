//
// Created by eugen on 21/07/2024.
//
#include "gtest/gtest.h"
#include "../TodoList.h"
TEST(TodoListTest, CreateTodoList) {
    TodoList todoList("My List");
    EXPECT_EQ(todoList.getName(), "My List");
}

TEST(TodoListTest, AddActivity) {//Test per aggiungere attività
    TodoList todoList("My List");
    Activity activity1("Vai a camminare", Date(12, 9, 2024), Time(10, 0), false);
    todoList.addActivity(activity1);

    EXPECT_NO_THROW(todoList.getActivity("Vai a camminare"));
}

TEST(TodoListTest, RemoveActivity) {// Test per rimuovere un'attività
    TodoList todoList("My List");
    Activity activity1("Vai a camminare", Date(12, 9, 2024), Time(10, 0), false);
    todoList.addActivity(activity1);

    todoList.removeActivity(activity1);
    EXPECT_THROW(todoList.getActivity("Vai a camminare"), TodoList::TodoListException);
}

TEST(TodoListTest, GetActivityByName) {// Test per recuperare un'attività per nome
    TodoList todoList("My List");
    Activity activity1("Vai a camminare", Date(12, 9, 2024), Time(10, 0), false);
    todoList.addActivity(activity1);

    Activity retrievedActivity = todoList.getActivity("Vai a camminare");
    EXPECT_EQ(retrievedActivity.getDescription(), "Vai a camminare");
}

TEST(TodoListTest, GetTotalActivities) {// Test per ottenere il numero totale di attività
    TodoList todoList("My List");
    Activity activity1("Vai a camminare", Date(12, 9, 2024), Time(10, 0), false);
    Activity activity2("Vai in palestra", Date(13, 9, 2024), Time(9, 0), true);

    todoList.addActivity(activity1);
    todoList.addActivity(activity2);

    todoList.NumberActivities();
    EXPECT_EQ(todoList.getActivitiesToDo().size(), 1);
}

TEST(TodoListTest, GetCompletedActivities) {// Test per ottenere il numero di attività completate
    TodoList todoList("My List");
    Activity activity1("Vai a camminare", Date(12, 9, 2024), Time(10, 0), false);
    Activity activity2("Vai in palestra", Date(13, 9, 2024), Time(9, 0), true);

    todoList.addActivity(activity1);
    todoList.addActivity(activity2);

    std::list<Activity> completedActivities = todoList.getCompletedActivities();
    EXPECT_EQ(completedActivities.size(), 1);
    EXPECT_EQ(completedActivities.front().getDescription(), "Vai in palestra");
}

TEST(TodoListTest, SaveAndLoadFromFile) {// Test per il salvataggio e il caricamento da file
    TodoList todoListOut("My List");
    Activity activity1("Vai a camminare", Date(12, 9, 2024), Time(10, 0), false);
    Activity activity2("Vai in palestra", Date(13, 9, 2024), Time(9, 0), true);

    todoListOut.addActivity(activity1);
    todoListOut.addActivity(activity2);

    std::string filename = "todo_list.txt";
    todoListOut.savetoFile(filename);

    TodoList todoListIn("Loaded List");
    todoListIn.loadFromFile(filename);

    EXPECT_NO_THROW(todoListIn.getActivity("Vai a camminare"));
    EXPECT_NO_THROW(todoListIn.getActivity("Vai in palestra"));
}

TEST(TodoListTest, NumberActivitiesToDo) {// Test per contare le attività da fare
    TodoList todoList("My List");
    Activity activity1("Vai a camminare", Date(12, 9, 2024), Time(10, 0), false);
    Activity activity2("Vai in palestra", Date(13, 9, 2024), Time(9, 0), true);

    todoList.addActivity(activity1);
    todoList.addActivity(activity2);

    int toDoCount = todoList.NumberActivitiestoDo();
    EXPECT_EQ(toDoCount, 1);
}

TEST(TodoListTest, NumberActivitiesDone) {// Test per contare le attività completate
    TodoList todoList("My List");
    Activity activity1("Vai a camminare", Date(12, 9, 2024), Time(10, 0), false);
    Activity activity2("Vai in palestra", Date(13, 9, 2024), Time(9, 0), true);

    todoList.addActivity(activity1);
    todoList.addActivity(activity2);

    int completedCount = todoList.NumberActivitiesDone();
    EXPECT_EQ(completedCount, 1);
}



