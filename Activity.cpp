//
// Created by eugen on 11/07/2024.
//
#include"Activity.h"

#include <utility>
Activity::Activity (std::string  desc , const Date& d,const Time& t,bool comp)
        : description(std::move(desc)),data(d),time(t), completed(comp) {
    if (description.empty()) {
        throw ActivityException("Description cannot be empty");
    }
}

 std::string  Activity:: getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &desc) {
    if (desc.empty()) {
        throw ActivityException("Description cannot be empty");
    }
    Activity::description = desc;
}

bool Activity:: isCompleted() const {
    return completed;
}

 Time Activity:: getTime() const {
    return time;
}

void Activity:: setTime(const Time& t) {
    Activity::time = t;
}

void Activity::setCompleted(bool comp) {
    Activity::completed = comp;
}

Date Activity:: getData() const {
    return data;
}

void Activity:: setData(const Date &d) {
    Activity::data = d;
}
void Activity::doneActivity(){
    if(!isCompleted()){
        completed=true;
        std::cout<<description<<"Completed"<<std::endl;
    }
}


void Activity::saveToFile(std::ofstream& outFile) const {//salvare attività su disco
    outFile << description << "\n";
    data.saveToFile(outFile);
    time.saveToFile(outFile);
    outFile << completed << "\n";
}


void Activity:: loadFromFile(std::ifstream& inFile) {//caricare attività su disco
    std::getline(inFile, description);
    if (description.empty()) {
        throw ActivityException("Description cannot be empty");
    }
    data.loadFromFile(inFile);
    time.loadFromFile(inFile);
    inFile >> completed;

}


void Activity:: print() const {// stampa attività
    std::cout << description << " - ";
    data.print();
    time.print();
}