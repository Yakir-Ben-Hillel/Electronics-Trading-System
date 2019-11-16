#include "../include/system.h"
Customer::Customer(const char *username, const char *password, const Address *address, const Product **wishlist, int size = 0)
{
    setName(username);
    setPassword(password);
    setWishList(wishlist);
    setSize(size);
    setAddress(address);
}

Customer::Customer(const Customer &other)
{
    setName(other.c_user_name);
    setPassword(other.c_password);
    setAddress(other.c_address);
    setSize(other.c_wish_size);
    setWishList(other.c_wishList);
}

Customer::~Customer()
{
    delete[] c_user_name;
    delete c_address;
    for (int i = 0; i < c_wish_size; i++)
    {
        delete c_wishList[i];
    }
    delete[] c_wishList;
    c_wish_size = 0;
}

bool Customer::setSize(int size)
{
    if (size < 0)
    {
        cout << "size cannot be negative" << endl;
        return false;
    }
    c_wish_size = size;
    return true;
}

bool Customer::setName(const char *userName)
{
    c_user_name = new char[strlen(userName) + 1];
    strcpy(c_user_name, userName);
    return true;
}

bool Customer::setAddress(const Address *address)
{
    c_address = new Address(*address);
    return true;
}

bool Customer::setPassword(const char *password)
{
    if (strlen(password) <= 10)
    {
        strcpy(c_password, password);
        return true;
    }
    cout << "the password must be 10 chars max" << endl;
    return false;
}

bool Customer::setWishList(const Product **wishList)
{
    c_wishList = new Product *[c_wish_size];
    for (int i = 0; i < c_wish_size; i++)
    {
        c_wishList[i] = new Product(*wishList[i]);
    }
    return true;
}

const char *Customer::getName() const
{
    return c_user_name;
}

const Address *Customer::getAddress() const
{
    return c_address;
}

const char *Customer::getPassWord() const
{
    return c_password;
}

const Product **Customer::getWishList() const
{
    return c_wishList;
}

int Customer::getSize() const
{
    return c_wish_size;
}