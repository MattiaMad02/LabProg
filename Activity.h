//
// Created by eugen on 10/07/2024.
//

#ifndef LABPROGR_ACTIVITY_H
#define LABPROGR_ACTIVITY_H
#include<string>
#include "Date.h"
#include <fstream>
#include "Time.h"
#include <stdexcept>
class Activity {
public:
    explicit Activity(std::string  desc = "", const Date& date = Date(),const Time& time=Time(),bool comp=false);


    std::string  getDescription() const;

    void setDescription(const std::string &description);

    bool isCompleted() const ;

    Time getTime() const;

    void setTime(const Time &time);

    void setCompleted(bool completed);

    Date getData() const;

    void setData(const Date &data) ;
    void doneActivity();


    void saveToFile(std::ofstream& outFile) const ;//salvare attività su disco



    void loadFromFile(std::ifstream& inFile);//caricare attività su disco



    void print() const ;// stampa attività
    class ActivityException : public std::runtime_error {
    public:
        explicit ActivityException(const std::string& message) : std::runtime_error(message) {}
    };
private:
    Date data;
    Time time;
    std::string description;
    bool completed;
};


#endif //LABPROGR_ACTIVITY_H
