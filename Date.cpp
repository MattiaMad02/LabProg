//
// Created by eugen on 11/07/2024.
//
#include "Date.h"
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date& Date:: operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

int Date:: getDay() const {
    return day;
}

void Date:: setDay(int d) {
    Date::day = d;
}

int Date::getMonth() const {
    return month;

}

void Date::setMonth(int m) {
    Date::month = m;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int y) {
    Date::year = y;
}

bool Date::isLeapYear() const {//guardo se anno bisestile
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int Date::daysInMonth() const {//numero giusto di giorni nel mese
    static const std::array<int, 12> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear()) {
        return 29;
    }
    return days[month - 1];
}
bool Date::isValidDate() const {//validita' della data
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > daysInMonth()) {
        return false;
    }
    return true;
}
void Date::print() const {
    if (isValidDate()) {
        std::cout << (day < 10 ? "0" : "") << day << "/"
                  << (month < 10 ? "0" : "") << month << "/"
                  << year << std::endl;
    } else {
        std::cout << "Invalid date" << std::endl;
    }
}

void Date::saveToFile(std::ofstream& outFile) const {//salvare data su disco
    outFile << day << " " << month << " " << year << "\n";
}


void Date:: loadFromFile(std::ifstream& inFile) {//caricare data su disco
    inFile >> day >> month >> year;
}
