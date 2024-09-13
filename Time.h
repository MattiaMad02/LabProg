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
   explicit Time(int h=0, int m=0);
   int getOra() const;
   void setOra(int ora);
   int getMinuti() const;
   void setMinuti(int minuti);
   void print() const;
    class TimeException : public std::runtime_error {
    public:
        explicit TimeException(const std::string& message) : std::runtime_error(message) {}
    };

private:
    int ore;
    int minuti;
    bool isValidTime() const{
        return (ore >= 0 && ore < 24) && (minuti>= 0 && minuti < 60);
    }//validità orario
};


#endif //LABPROGR_TIME_H
