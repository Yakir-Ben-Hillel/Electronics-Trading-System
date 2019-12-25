#include "../../include/system.h"
#include <typeinfo>

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
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
   if (givenday > 31 || givenday < 1)
   {
      cout << "day has to be between the values 1-31(depends on the month)" << endl;
      return false;
   }
   m_day = givenday;
   return true;
}
bool Date::setMonth(unsigned int givenmonth)
{
   if (givenmonth > 12 || givenmonth < 1)
   {
      cout << "month has to be between the values 1-12" << endl;
      return false;
   }
   m_month = givenmonth;
   return true;
}
bool Date::setYear(unsigned int givenyear)
{
   m_year = givenyear;
   return true;
}
ostream&operator<<(ostream&out,const Date&date)
{
   if(typeid(out)==typeid(ofstream))
   {
      out<<date.m_day<<" "<<date.m_month<<" "<<date.m_year<<" ";
   }
   else
   {
      out<<"Day: "<<date.m_day<<" Month: "<<date.m_month<<" Year: "<<date.m_year<<endl;
   }
   return out;
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