#pragma once
#ifndef __SystemException_H
#define __SystemException_H

#include "system.h"

class SystemException
{
public:
    virtual void show() const = 0 { cout << "some error as occurred, please call support!" << endl; };
};
class UserException : public SystemException
{
protected:
    char *name;
    char *password;
    Address address;

public:
    UserException(char *name, char *password, Address &address)
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
    virtual void show() const override;
};
class ProductException : public SystemException
{
protected:
    char *p_name;
    float price;

public:
    ProductException(const char *name, float price) : price(price) { this->p_name = strdup(name); };
    virtual ~ProductException() { delete[] p_name; };
    virtual void show() const override;
};
class DateException : public SystemException
{
protected:
    int day, month, year;

public:
    DateException(int day, int month, int year) : day(day), month(month), year(year){};
    virtual ~DateException(){};
    virtual void show() const override;
};
class FeedBackException : public SystemException
{
protected:
public:
};
class AddressException : public SystemException
{
protected:
public:
};
class OrderException : public SystemException
{
protected:
public:
};
#endif