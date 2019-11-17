#include "product.h"

Product::Product(const char *name, eCategory category, const char *seller, unsigned int serial = 0, float price = 0)
{
    setName(name);
    setCategory(category);
    setSerialNumber(serial);
    setPrice(price);
    setSellerName(seller);
    cout << "in product constructor" << endl; //check its working remove befor uploading
}

Product::Product(const Product &other)
{
    p_name = new char[strlen(other.p_name) + 1];
    strcpy(p_name, other.p_name);
    p_price = other.p_price;
    p_serialNumber = other.p_serialNumber;
    p_category = other.p_category;
    setSellerName(other.seller_name);
    cout << "in copy constructor" << endl; //check its working remove befor uploading
}

Product::~Product()
{
    delete[] p_name;
    delete[] seller_name;
    cout << "in product distructor" << endl; //check its working remove befor uploading
}

bool Product::setName(const char *name)
{
    p_name = new char[strlen(name) + 1];
    strcpy(p_name, name);
    return true;
}

bool Product::setPrice(float price)
{
    if (price < 0)
    {
        cout << "price are not able to be negative!" << endl;
        return false;
    }
    p_price = price;
    return true;
}

bool Product::setSerialNumber(unsigned int serial)
{
    p_serialNumber = serial;
    return true;
}

bool Product::setCategory(eCategory category)
{
    if (category == Children || category == Office || category == Electricity || category == Clothing)
    {
        p_category = category;
        return true;
    }
    cout << "the section you have chosen is not allowed" << endl;
    cout << "please choose one of the available sections" << endl;
    return false;
}
bool Product::setSellerName(const char *seller)
{
    seller_name = new char[strlen(seller) + 1];
    strcpy(seller_name, seller);
    return true;
}

const char *Product::getName() const
{
    return p_name;
}

float Product::getPrice() const
{
    return p_price;
}

Product::eCategory Product::getCategory() const
{
    return p_category;
}

unsigned int Product::getSerialNumber() const
{
    return p_serialNumber;
}
const char *Product::getSellerName() const
{
    return seller_name;
}