//
// Created by eugen on 11/07/2024.
//
#include "Date.h"
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if (!isValidDate()) {
        throw DateException("Invalid date provided");
    }
}

bool Date:: operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}

int Date:: getDay() const {
    return day;
}

void Date:: setDay(int d) {
    day = d;
    if (!isValidDate()) {
        throw DateException("Invalid day value");
    }
}

int Date::getMonth() const {
    return month;

}

void Date::setMonth(int m) {
    month = m;
    if (!isValidDate()) {
        throw DateException("Invalid month value");
    }
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int y) {
    year = y;
    if (!isValidDate()) {
        throw DateException("Invalid year value");
    }
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

void Date::print() const {
    if (isValidDate()) {
        std::cout << (day < 10 ? "0" : "") << day << "/"
                  << (month < 10 ? "0" : "") << month << "/"
                  << year << std::endl;
    } else {
        std::cout << "Invalid date" << std::endl;
    }
}

