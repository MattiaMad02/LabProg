//
// Created by eugen on 11/07/2024.
//

#include "TodoList.h"

void TodoList:: addActivity(const Activity& activity){
    activities.push_back(activity);
}

Activity TodoList:: getActivity(const std::string& nameA){
    for(auto itr=activities.begin();itr!=activities.end();){
        if(itr->getDescription()==nameA){
            itr->print();
        }else{
            itr++;
        }
    }
    return Activity();
}

void TodoList::printList() {
    for(auto itr=activities.begin();itr!=activities.end();){
        itr->print();
        itr++;
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
int TodoList:: NumberActivitiestoDo(){
    size_t count = 0;
    for (const auto& activity : activities) {
        if (!activity.isCompleted()) {
            ++count;
        }
    }
    std::cout<<count<<std::endl;
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
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
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
            inFile.ignore(); // Ignore the newline character after the boolean
            activities.emplace_back(description, Date(day, month, year), Time(hour, minute), completed);
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}