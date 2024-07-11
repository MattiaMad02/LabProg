//
// Created by eugen on 11/07/2024.
//
#include "Time.h"
Time::Time(int h, int m): ore(h),minuti(m){}

int Time::getOra() const {
    return ore;
}

void Time:: setOra(int h) {
    Time::ore = h;
}

int Time:: getMinuti() const {
    return minuti;
}

void Time:: setMinuti(int m) {
    Time::minuti = m;
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
}
