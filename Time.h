//
// Created by eugen on 11/07/2024.
//

#ifndef LABPROGR_TIME_H
#define LABPROGR_TIME_H
#include<iostream>
#include<string>
#include<fstream>
#include <stdexcept>
class Time {
public:
    Time(int h=0, int m=0);

    int getOra() const;

    void setOra(int ora);

    int getMinuti() const;

    void setMinuti(int minuti);
    bool isValidTime() const;//validità orario

    void print() const;
    void saveToFile(std::ofstream& outFile) const;//salvataggio orario

    void loadFromFile(std::ifstream& inFile);//caricamento orario
    class TimeException : public std::runtime_error {
    public:
        explicit TimeException(const std::string& message) : std::runtime_error(message) {}
    };

private:
    int ore;
    int minuti;
};


#endif //LABPROGR_TIME_H
