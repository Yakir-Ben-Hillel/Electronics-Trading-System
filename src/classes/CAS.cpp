#include "../../include/CAS.h"

CAS::CAS(const User &user, const Customer &customer, const Seller &seller)
    : User(user), Customer(customer), Seller(seller)
{
}
CAS::CAS(char *username, char *password, Address &address)
    : User(username, password, address),
      Customer(username, password, address),
      Seller(username, password, address)
{
}
CAS::CAS(const CAS &other) : User(other), Customer(other), Seller(other)
{
}
CAS::CAS(const User &user) : User(user), Customer(user), Seller(user)
{
}
CAS::~CAS()
{
}