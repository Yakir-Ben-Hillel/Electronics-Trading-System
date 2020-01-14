#pragma once
#ifndef __DATE_H
#define __DATE_H
#include "system.h"
class Date
{
public:
    //constructors and distructors
    Date(unsigned int day, unsigned int month, unsigned int year) noexcept(false);
    Date(const Date &other);
    ~Date() = default;
    //seters and geters
    bool setDay(unsigned int givenday);
    bool setMonth(unsigned int givenmonth);
    bool setYear(unsigned int givenyear);

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    friend ostream &operator<<(ostream &out, const Date &date);
    friend istream &operator>>(istream &out, Date &date);

private:
    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;
};

#endif