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
char* name;
char* password;
Address address;
public:
UserException(char* name,char* password,Address& address) {this->name=strdup(name); 
this->password=strdup(password); this->address=address;};
virtual ~UserException() {delete[] name; delete[] password;};
virtual void show() const override;
};
class ProductException : public SystemException
{
};
class DateException : public SystemException
{
};
class FeedBackException : public SystemException
{
};
class AddressException : public SystemException
{
};
class OrderException : public SystemException
{
};
#endif