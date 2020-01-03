#pragma once
#ifndef __SystemException_H
#define __SystemException_H

#include "system.h"

class SystemException
{
public:
   virtual void show() const = 0 {cout<<"some error as occurred, please call support!"<<endl;};
};
class UserException:public SystemException
{
   
};
class CustomerException:virtual public UserException
{

};
class SellerException:virtual public UserException
{

};
class CASException:public CustomerException,public SellerException
{

};
class ProductException: public SystemException
{

};
class DateException :public SystemException
{

};
class FeedBackException:public SystemException
{

};
class AddressException:public SystemException
{

};
class OrderException:public SystemException
{

};
#endif