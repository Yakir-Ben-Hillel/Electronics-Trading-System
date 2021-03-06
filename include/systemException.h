#pragma once
#ifndef __SystemException_H
#define __SystemException_H

//forward declarations
class Address;
class Date;
void Terminate();
#include <string>
/*
this file includes all the exception classes, all exceptions inheritance from the 
abstract SystemException class.
each class knows what is the problem and by using the function show it prints a message to the console
all the implemantions are in the cpp file.
*/
class SystemException
{
public:
    virtual ~SystemException() {}
    virtual void show() const = 0;
};
class ProductException : public SystemException
{
protected:
    string p_name;
    float price;

public:
    ProductException(const string &name, float price);
    virtual ~ProductException();
    virtual void show() const override final;
};
class DateException : public SystemException
{
protected:
    int day, month, year;

public:
    DateException(int day, int month, int year);
    virtual ~DateException() {}
    virtual void show() const override;
};
class FeedBackException : public SystemException
{
protected:
    const Date& date;
    string note;

public:
    FeedBackException(const Date &date, const string &note);
    virtual ~FeedBackException();
    virtual void show() const override final;
};
class AddressException : public SystemException
{
protected:
    unsigned int apartmentNumber;
    string streetName;
    string cityName;

public:
    AddressException(unsigned int apartmentNumber, const string &streetName, const string &cityName);
    virtual ~AddressException();
    virtual void show() const override final;
};
class UserException : public SystemException
{
protected:
    string name;
    string password;
    const Address &address;

public:
    UserException(const string &name, const string &password, const Address &address);
    virtual ~UserException();
    virtual void show() const override final;
};
#endif