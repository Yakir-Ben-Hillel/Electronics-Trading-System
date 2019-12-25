#include "../../include/CAS.h"

CAS::CAS(const Customer &customer, const Seller &seller)
    : User(customer), Customer(customer), Seller(seller)
{
}
CAS::CAS(const CAS &other) : User(other), Customer(other), Seller(other)
{
}
CAS::CAS(ifstream &inFile) : User(inFile), Customer(inFile), Seller(inFile)
{
}
CAS::~CAS()
{
}
// istream &operator>>(istream &in, CAS &cas)
// {
//     in >> (User &)cas;
//     in >> cas.m_username >> cas.m_password;
//     in >> cas.m_address >> cas.stock_array_physical_length;
//     in >> cas.stock_array_logical_length;
//     for (int i = 0; cas.stock_array_logical_length; i++)
//     {
//         in >> *cas.s_stock[i];
//     }
//     in >> cas.feedbacks_array_physical_length;
//     in >> cas.feedbacks_array_logical_length;
//     for (int i = 0; i < cas.feedbacks_array_logical_length; i++)
//         in >> *cas.feedBack_array[i];

//     in >> cas.c_wish_physical_size >> cas.c_wish_logical_size;
//     for (int i = 0; i < cas.c_wish_logical_size; i++)
//         in >> *cas.c_wishList[i];
//     in >> cas.order_physical_size >> cas.order_logical_size;
//     for (int i = 0; i < cas.order_logical_size; i++)
//         in >> *cas.orders_history[i];
// }
void CAS::toOs(ostream &out) const
{
}