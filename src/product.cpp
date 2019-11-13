#include "product.h"

bool Product::setName(const char* name)
{
    p_name=new char[strlen(name)+1];
    strcpy(p_name,name);
    return true;
}

bool Product::setPrice(float price)
{
    if(price<0)
     {
         cout<<"price are not able to be negative!"<<endl;
         return false;
     } 
     p_price=price;
     return true;
}

bool Product:: setSerialNumber(unsigned int serial)
{
    p_serialNumber=serial;
    return true;
}

bool Product:: setCategory(eCategory category)
{
    if(category==Children||category==Office||category==Electricity||category==Clothing)
    {
        p_category=category;
        return true;
    }
    cout<<"the section you have chosen is not allowed"<<endl;
    cout<<"please choose one of the available sections"<<endl;
    return false;
}

const char* Product::getName() const
{
    return p_name;
}

float Product:: getPrice() const
{
    return p_price;
}

Product:: eCategory Product:: getCategory() const
{
    return p_category;
}

unsigned int Product:: getSerialNumber() const
{
    return p_serialNumber;
}