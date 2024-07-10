//
// Created by eugen on 10/07/2024.
//

#ifndef LABPROGR_DATE_H
#define LABPROGR_DATE_H
#include<iostream>
#include<string>
#include <array>
#include <fstream>
class Date {
public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}


    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        Date::day = day;
    }

    int getMonth() const {
         return month;

    }

    void setMonth(int month) {
        Date::month = month;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Date::year = year;
    }

    bool isLeapYear() const {//guardo se anno bisestile
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    int daysInMonth() const {//numero giusto di giorni nel mese
        static const std::array<int, 12> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && isLeapYear()) {
            return 29;
        }
        return days[month - 1];
    }
    bool isValidDate() const {//validita' della data
        if (month < 1 || month > 12) {
            return false;
        }
        if (day < 1 || day > daysInMonth()) {
            return false;
        }
        return true;
    }
    void print() const {
        if (isValidDate()) {
            std::cout << (day < 10 ? "0" : "") << day << "/"
                      << (month < 10 ? "0" : "") << month << "/"
                      << year << std::endl;
        } else {
            std::cout << "Invalid date" << std::endl;
        }
    }

    void saveToFile(std::ofstream& outFile) const {//salvare data su disco
        outFile << day << " " << month << " " << year << "\n";
    }


    void loadFromFile(std::ifstream& inFile) {//caricare data su disco
        inFile >> day >> month >> year;
    }

private:
    int day;
    int month;
    int year;
};


#endif //LABPROGR_DATE_H
