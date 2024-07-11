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
    Activity getActivity(const std::string& nameA);
    int NumberActivitiestoDo();
    void printList();
    void savetoFile(const std::string& filename)const;
    void loadFromFile(const std::string& filename);
private:
    std::list<Activity> activities;
};


#endif //LABPROGR_TODOLIST_H
