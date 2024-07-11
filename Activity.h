//
// Created by eugen on 10/07/2024.
//

#ifndef LABPROGR_ACTIVITY_H
#define LABPROGR_ACTIVITY_H
#include<string>
#include "Date.h"
#include <fstream>
#include "Time.h"
class Activity {
public:
    Activity (const std::string& desc = "", const Date& date = Date(),const Time& time=Time(),bool comp=false)
            : description(desc),data(data),time(time), completed(comp) {}

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        Activity::description = description;
    }

    bool isCompleted() const {
        return completed;
    }

    const Time &getTime() const {
        return time;
    }

    void setTime(const Time &time) {
        Activity::time = time;
    }

    void setCompleted(bool completed) {
        Activity::completed = completed;
    }

    const Date &getData() const {
        return data;
    }

    void setData(const Date &data) {
        Activity::data = data;
    }
    void doneActivity(){
        if(isCompleted()){
            completed=true;
            std::cout<<description<<"Fatta"<<std::endl;
        }
    }


    void saveToFile(std::ofstream& outFile) const {//salvare attività su disco
        outFile << description << "\n";
        data.saveToFile(outFile);
        time.saveToFile(outFile);
    }


    void loadFromFile(std::ifstream& inFile) {//caricare attività su disco
        std::getline(inFile, description);
        data.loadFromFile(inFile);
        time.loadFromFile(inFile);
    }


    void print() const {// stampa attività
        std::cout << description << " - ";
        data.print();
        time.print();
    }
private:
    Date data;
    Time time;
    std::string description;
    bool completed;
};


#endif //LABPROGR_ACTIVITY_H
