//
// Created by eugen on 11/07/2024.
//

#ifndef LABPROGR_TODOLIST_H
#define LABPROGR_TODOLIST_H
#include "Activity.h"
#include <list>

class TodoList {
public:
    explicit TodoList(const std::string &name);
    void addActivity(const Activity& activity);
    void removeActivity(const Activity& activity);
    Activity getActivity(const std::string& nameA)const;
    int NumberActivitiestoDo()const;
    int NumberActivitiesDone()const;
    void printList();
    void savetoFile(const std::string& filename)const;
    void loadFromFile(const std::string& filename);
    Activity getActivityByDate(const Date& date) const;
    const std::string &getName() const;
    void setName(const std::string &name);
    void NumberActivities()const;
    std::list<Activity> getCompletedActivities() const;
    std::list<Activity>getActivitiesToDo()const;
    class TodoListException : public std::runtime_error {
    public:
        explicit TodoListException(const std::string& message) : std::runtime_error(message) {}
    };
private:
    std::list<Activity> activities;
    std::string name;
};


#endif //LABPROGR_TODOLIST_H
