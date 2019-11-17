#ifndef __DATE_H
#define __DATE_H

class Date
{
public:
    //constructors and distructors
    Date() = default;
    Date(unsigned int day, unsigned int month, unsigned int year);
    Date(const Date &other);
    ~Date() = default;
    //seters and geters
    bool setDay(unsigned int givenday);
    bool setMonth(unsigned int givenmonth);
    bool setYear(unsigned int givenyear);

    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

private:
    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;
};

#endif