//
// Created by eugen on 11/07/2024.
//

#ifndef LABPROGR_TODOLIST_H
#define LABPROGR_TODOLIST_H
#include "Activity.h"
#include <list>

class TodoList {
public:

    void addActivity(const Activity& activity);
    void removeActivityCompleted();
    Activity getActivity(const std::string& nameA)const;
    int NumberActivitiestoDo()const;
    void printList();
    void savetoFile(const std::string& filename)const;
    void loadFromFile(const std::string& filename);
    Activity getActivityByDate(const Date& date) const;
private:
    std::list<Activity> activities;
    class TodoListException : public std::runtime_error {
    public:
        explicit TodoListException(const std::string& message) : std::runtime_error(message) {}
    };
};


#endif //LABPROGR_TODOLIST_H
