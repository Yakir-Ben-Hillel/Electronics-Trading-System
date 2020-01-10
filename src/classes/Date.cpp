#include "../../include/system.h"
#include <typeinfo>

Date::Date(unsigned int day, unsigned int month, unsigned int year) noexcept(false)
{
   if (month <= 0 || month > 12 || day <= 0 || day > 31)
      throw DateException(day, month, year);
   setDay(day);
   setMonth(month);
   setYear(year);
}
Date::Date(const Date &other)
{
   setDay(other.m_day);
   setMonth(other.m_month);
   setYear(other.m_year);
}
bool Date::setDay(unsigned int givenday)
{
   m_day = givenday;
   return true;
}
bool Date::setMonth(unsigned int givenmonth)
{
   m_month = givenmonth;
   return true;
}
bool Date::setYear(unsigned int givenyear)
{
   m_year = givenyear;
   return true;
}
ostream &operator<<(ostream &out, const Date &date)
{
   if (typeid(out) == typeid(ofstream))
   {
      out << date.m_day << " " << date.m_month << " " << date.m_year << " ";
   }
   else
   {
      out << date.m_day << "/" << date.m_month << "/" << date.m_year << endl;
   }
   return out;
}
istream &operator>>(istream &in, Date &date)
{
   in >> date.m_day >> date.m_month >> date.m_year;
   return in;
}
unsigned int Date::getDay() const
{
   return m_day;
}
unsigned int Date::getMonth() const
{
   return m_month;
}
unsigned int Date::getYear() const
{
   return m_year;
}