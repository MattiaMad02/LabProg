//
// Created by eugen on 10/07/2024.
//

#ifndef LABPROGR_DATE_H
#define LABPROGR_DATE_H
#include<iostream>
#include<string>
#include <array>
#include <fstream>
#include <stdexcept>
class Date {
public:
    Date(int d = 1, int m = 1, int y = 2000);


    bool operator==(const Date& other) const;


    int getDay() const;

    void setDay(int day);

    int getMonth() const ;


    void setMonth(int month);

    int getYear() const ;

    void setYear(int year) ;

    bool isLeapYear() const;//guardo se anno bisestile

    int daysInMonth() const; //numero giusto di giorni nel mese


    bool isValidDate() const;//validita' della data

    void print() const;

    void saveToFile(std::ofstream& outFile) const;//salvare data su disco


    void loadFromFile(std::ifstream& inFile);//caricare data su disco
    class DateException : public std::runtime_error {
    public:
        explicit DateException(const std::string& message) : std::runtime_error(message) {}
    };

private:
    int day;
    int month;
    int year;
};


#endif //LABPROGR_DATE_H
