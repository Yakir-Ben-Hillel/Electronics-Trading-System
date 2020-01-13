#include "../../include/CAS.h"
CAS::CAS(const string &username, const string &password, Address &address) noexcept(false)
    : User(username, password, address)
{
}
CAS::CAS(const Customer &customer, const Seller &seller)
    : User(customer), Customer(customer), Seller(seller)
{
}
CAS::CAS(const CAS &other) : User(other), Customer(other), Seller(other)
{
}
CAS::CAS(const CAS &&other) : User(other), Customer(other), Seller(other)
{
}
CAS::CAS(ifstream &inFile)
{
    inFile >> *this;
}
CAS::~CAS()
{
}
void CAS::toOs(ostream &out) const
{
    Seller::toOs(out);
    Customer::toOs(out);
}

User *CAS::clone() const
{
    return new CAS(*this);
}

bool CAS::operator==(const User &other) const
{
    if (!User::operator==(other))
        return false;
    return true;
}
