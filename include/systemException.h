#pragma once
#ifndef __SystemException_H
#define __SystemException_H

#include <iostream>
using namespace std;
#include <string.h>

//forward declarations
class Address;
class Date;

class SystemException
{
public:
    virtual ~SystemException(){}
    virtual void show() const = 0;
};
class UserException : public SystemException
{
protected:
    char *name;
    char *password;
    Address address;
public:
    UserException(const char *name,const char *password,const Address &address)
    {
        this->name = strdup(name);
        this->password = strdup(password);
        this->address = address;
    };
    virtual ~UserException()
    {
        delete[] name;
        delete[] password;
    };
    virtual void show() const override
    {
        if (strcmp(name, "") == 0)
            cout << "Error chosen name cannot be blank!" << endl;
        if (strcmp(password, "") == 0 || strlen(password) > 10)
            cout << "Error chosen password is wrong!" << endl;
        AddressException Ae(address);
        Ae.show();
    }
};
class ProductException : public SystemException
{
protected:
    char *p_name;
    float price;

public:
    ProductException(const char *name, float price) : price(price) { this->p_name = strdup(name); };
    virtual ~ProductException() { delete[] p_name; };
    virtual void show() const override
    {
        if (price < 0)
            cout << "price cannot be negative!" << endl;
        if (strcmp(p_name, "") == 0)
            cout << "Error, product name cannot be blank!" << endl;
    }
};
class DateException : public SystemException
{
protected:
    int day, month, year;

public:
    DateException(int day, int month, int year) : day(day), month(month), year(year){};
    virtual ~DateException(){};
    virtual void show() const override
    {
        if (day <= 0 || day > 31)
            cout << "Error, day must be in the range of 1-31" << endl;
        if (month <= 0 || month > 12)
            cout << "Error, month must be in the range of 1-12" << endl;
        //year can be negative or positive!
        return;
    }
};
class FeedBackException : public SystemException
{
protected:
    Date date;
    char *note;

public:
    FeedBackException(Date date, char *note) : date(date) { this->note = strdup(note); };
    virtual ~FeedBackException() { delete[] note; };
    virtual void show() const
    {
        if (strcmp(note, "") == 0)
            cout << "Error, feedback must contain at least one letter! " << endl;
        DateException e((int)date.getDay(), (int)date.getMonth(), (int)date.getYear());
        e.show();
    };
};
class AddressException : public SystemException
{
protected:
    Address address;

public:
    AddressException(const Address &other) { address = other; };
    virtual ~AddressException(){};
    virtual void show() const override
    {
        if (address.getApartmentNumber() <= 0)
            cout << "Error, apartment number is wrong!" << endl;
        if (strcmp(address.getCityName(), "") == 0)
            cout << "Error, city name cannot be blank!" << endl;
        if (strcmp(address.getStreetName(), "") == 0)
            cout << "Error, street name cannot be blank!" << endl;
        return;
    }
};

void Terminate()
{
    cout<<"Something went wrong, please call support for further information!"<<endl;
}
#endif