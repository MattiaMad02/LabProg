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
    explicit Date(int d = 1, int m = 1, int y = 2000);
    bool operator==(const Date& other) const;
    int getDay() const;
    void setDay(int day);
    int getMonth() const ;
    void setMonth(int month);
    int getYear() const ;
    void setYear(int year) ;
    bool isLeapYear() const;//guardo se anno bisestile
    int daysInMonth() const; //numero giusto di giorni nel mese
    void print() const;
    class DateException : public std::runtime_error {
    public:
        explicit DateException(const std::string& message) : std::runtime_error(message) {}
    };

private:
    int day;
    int month;
    int year;
    bool isValidDate() const{
        if (month < 1 || month > 12) {
            return false;
        }
        if (day < 1 || day > daysInMonth()) {
            return false;
        }
        return true;
    }
};


#endif //LABPROGR_DATE_H
