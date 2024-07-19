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
bool Time:: isValidTime() const {//validità orario
    return (ore >= 0 && ore < 24) && (minuti>= 0 && minuti < 60);
}
void Time:: print() const {
    if (isValidTime()) {
        std::cout << (ore < 10 ? "0" : "") << ore << ":"
                  << (minuti < 10 ? "0" : "") << minuti << std::endl;
    } else {
        std::cout << "Invalid time" << std::endl;
    }
}
void Time::saveToFile(std::ofstream& outFile) const {//salvataggio orario
    outFile << ore<< " " << minuti << "\n";
}
void Time:: loadFromFile(std::ifstream& inFile) {//caricamento orario
    inFile >> ore >> minuti;
    if (!isValidTime()) {
        throw TimeException("Invalid time loaded from file");
    }
}
