#include "../include/seller.h"
void Seller::setUserName(char *givenUserName)
{
    userName = new char[strlen(givenUserName) + 1];
    strcpy(givenUserName, userName);
}

void Seller::setAddress(char *givenAddress)
{
    address = new char[strlen(givenAddress) + 1];
    strcpy(givenAddress, address);
}
void Seller::setPassword(char *givenPassword)
{
    if (strlen(givenPassword) <= 10)
    {
        strcpy(givenPassword, password);
    }
    else
        cout << "Maximum password length is 10." << endl;
}
char *Seller::getUserName() const
{
    return userName;
}
char *Seller::getAddress() const
{
    return address;
}
