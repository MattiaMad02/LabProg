//
// Created by eugen on 11/07/2024.
//

#include "TodoList.h"
TodoList::TodoList(const std::string &name) : name(name) {
}

const std::string &TodoList::getName() const {
    return name;
}

void TodoList::setName(const std::string &name) {
    TodoList::name = name;
}

void TodoList:: addActivity(const Activity& activity){
    activities.push_back(activity);
}
void TodoList::removeActivity(const Activity& activity){
    for (auto itr = activities.begin(); itr != activities.end(); ++itr) {
        if (*itr == activity) {
            activities.erase(itr);
            std::cout << "Activity removed successfully." << std::endl;
            return;
        }
    }
    std::cerr << "Activity not found in the list." << std::endl;
}
Activity TodoList:: getActivity(const std::string& nameA)const{
    for (const auto& activity : activities) {
        if (activity.getDescription() == nameA) {
            return activity;
        }
    }
    throw TodoListException("Activity not found: " + nameA);
}
Activity TodoList::getActivityByDate(const Date& date) const{
    for (const auto& activity : activities){
        if(activity.getData().getDay()==date.getDay()&&activity.getData().getMonth()==date.getMonth()&&activity.getData().getYear()==date.getYear()){
            return activity;
        }
    }
    throw TodoListException("Activity not found for the given date.");
}

void TodoList::printList() {
    std::cout << "Todo List: " << name << std::endl;
    for (const auto& activity : activities) {
        activity.print();
    }
}

int TodoList:: NumberActivitiestoDo()const{
    int count = 0;
    for (const auto& activity : activities) {
        if (!activity.isCompleted()) {
            ++count;
        }
    }
    std::cout << "Number of activities to do: " << count << std::endl;
    return count;
}
int TodoList::NumberActivitiesDone() const {
    int count=0;
    for (const auto& activity : activities) {
        if (activity.isCompleted()) {
            ++count;
        }
    }
    std::cout << "Number of activities completed: " << count << std::endl;
    return count;

}
void TodoList:: savetoFile(const std::string& filename)const{
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& activity : activities) {
            activity.saveToFile(outFile);
        }
        outFile.close();
    } else {
        throw TodoListException("Unable to open file for writing: " + filename);
    }
}
void TodoList:: loadFromFile(const std::string& filename){
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        activities.clear();
        std::string description;
        int day, month, year, hour, minute;
        bool completed;
        while (std::getline(inFile, description) &&
               (inFile >> day >> month >> year >> hour >> minute >> completed)) {
            inFile.ignore();
            activities.emplace_back(description, Date(day, month, year), Time(hour, minute), completed);
        }

        inFile.close();
    } else {
        throw TodoListException("Unable to open file for reading: " + filename);
    }
}
void TodoList::NumberActivities() const {
    std::cout<<"Number of activities: "<<activities.size()<<std::endl;
}
std::list<Activity> TodoList::getCompletedActivities() const {
    std::list<Activity> completedActivities;
    for (const auto& activity : activities) {
        if (activity.isCompleted()) {
            completedActivities.push_back(activity);
        }
    }
    return completedActivities;
}
std::list<Activity>TodoList::getActivitiesToDo() const {
    std::list<Activity> ActivitiesToDo;
    for (const auto &activity: activities) {
        if (!activity.isCompleted()) {
            ActivitiesToDo.push_back(activity);
        }
    }
    return ActivitiesToDo;
}
