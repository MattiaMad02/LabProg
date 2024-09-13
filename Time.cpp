//
// Created by eugen on 11/07/2024.
//
#include "Time.h"
Time::Time(int h, int m): ore(h),minuti(m){
    if (!isValidTime()) {
        throw TimeException("Invalid time provided");
    }
}

int Time::getOra() const {
    return ore;
}

void Time:: setOra(int h) {
    ore = h;
    if (!isValidTime()) {
        throw TimeException("Invalid hour value");
    }
}

int Time:: getMinuti() const {
    return minuti;
}

void Time:: setMinuti(int m) {
    minuti = m;
    if (!isValidTime()) {
        throw TimeException("Invalid minute value");
    }
}
void Time:: print() const {
    if (isValidTime()) {
        std::cout << (ore < 10 ? "0" : "") << ore << ":"
                  << (minuti < 10 ? "0" : "") << minuti << std::endl;
    } else {
        std::cout << "Invalid time" << std::endl;
    }
}

