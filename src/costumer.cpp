#include "../include/costumer.h"
Costumer::Costumer(const char *username, const char *password, const char *address, const Product **wishlist, int size = 0)
{
    setName(username);
    setPassword(password);
    setWishList(wishlist);
    setSize(size);
    setAddress(address);
}

Costumer::Costumer(const Costumer &other)
{
    c_user_name = new char[strlen(other.c_user_name) + 1];
    strcpy(c_user_name, other.c_user_name);
    c_address = new char[strlen(other.c_address) + 1];
    strcpy(c_address, other.c_address);
    strcpy(c_password, other.c_password);

    c_wishList = new Product *[other.c_wish_size];
    c_wish_size = other.c_wish_size;
    for (int i = 0; i < c_wish_size; i++)
    {
        c_wishList[i] = new Product(*other.c_wishList[i]);
    }
}

Costumer::~Costumer()
{
    delete[] c_user_name;
    delete[] c_address;
    for (int i = 0; i < c_wish_size; i++)
    {
        delete c_wishList[i];
    }
    delete[] c_wishList;
    c_wish_size = 0;
}

bool Costumer::setSize(int size)
{
    if (size < 0)
    {
        cout << "size cannot be negative" << endl;
        return false;
    }
    c_wish_size = size;
    return true;
}

bool Costumer::setName(const char *userName)
{
    c_user_name = new char[strlen(userName) + 1];
    strcpy(c_user_name, userName);
    return true;
}

bool Costumer::setAddress(const char *address)
{
    c_address = new char[strlen(address) + 1];
    strcpy(c_address, address);
    return true;
}

bool Costumer::setPassword(const char *password)
{
    if (strlen(password) <= 10)
    {
        strcpy(c_password, password);
        return true;
    }
    cout << "the password must be 10 chars max" << endl;
    return false;
}

bool Costumer::setWishList(const Product **wishList)
{
    c_wishList = new Product *[c_wish_size];
    for (int i = 0; i < c_wish_size; i++)
    {
        c_wishList[i] = new Product(*wishList[i]);
    }
    return true;
}

const char *Costumer::getName() const
{
    return c_user_name;
}

const char *Costumer::getAddress() const
{
    return c_address;
}

const char *Costumer::getPassWord() const
{
    return c_password;
}

const Product **Costumer::getWishList() const
{
    return c_wishList;
}

int Costumer::getSize() const
{
    return c_wish_size;
}