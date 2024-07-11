//
// Created by eugen on 11/07/2024.
//

#ifndef LABPROGR_TIME_H
#define LABPROGR_TIME_H
#include<iostream>
#include<string>
#include<fstream>

class Time {
public:
    Time(int h=0, int m=0): ore(h),minuti(m){}

    int getOra() const {
        return ore;
    }

    void setOra(int ora) {
        Time::ore = ore;
    }

    int getMinuti() const {
        return minuti;
    }

    void setMinuti(int minuti) {
        Time::minuti = minuti;
    }
    bool isValidTime() const {//validità orario
        return (ore >= 0 && ore < 24) && (minuti>= 0 && minuti < 60);
    }
    void print() const {
        if (isValidTime()) {
            std::cout << (ore < 10 ? "0" : "") << ore << ":"
                      << (minuti < 10 ? "0" : "") << minuti << std::endl;
        } else {
            std::cout << "Invalid time" << std::endl;
        }
    }
    void saveToFile(std::ofstream& outFile) const {//salvataggio orario
        outFile << ore<< " " << minuti << "\n";
    }
    void loadFromFile(std::ifstream& inFile) {//caricamento orario
        inFile >> ore >> minuti;
    }

private:
    int ore;
    int minuti;
};


#endif //LABPROGR_TIME_H
