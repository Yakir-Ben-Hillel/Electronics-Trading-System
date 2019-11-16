#ifndef __DATE_H
#define __DATE_H

#include "system.h"

class Date
{
public:
    //constructors and distructors
    Date() = default;
    Date(unsigned int day, unsigned int month, unsigned int year);
    Date(Date &other);
    ~Date();
    //seters and geters
    bool setDay(unsigned int day);
    bool setMonth(unsigned int month);
    bool setYear(unsigned int year);

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

#endif