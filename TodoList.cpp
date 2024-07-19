//
// Created by eugen on 11/07/2024.
//

#include "TodoList.h"
#include<algorithm>
void TodoList:: addActivity(const Activity& activity){
    activities.push_back(activity);
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
    for (const auto& activity : activities) {
        activity.print();
    }
}
void TodoList:: removeActivityCompleted(){
    for(auto itr=activities.begin();itr!=activities.end();){
        if(itr->isCompleted()){
            itr=activities.erase(itr);

        }
        else{
            itr++;
        }
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