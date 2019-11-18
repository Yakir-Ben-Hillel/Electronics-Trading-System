#include "../include/includes.h"
System::System(const char *name, Customer **customers_array, Seller **sellers_array, unsigned int customers_array_size = 0, unsigned int sellers_array_size = 0)
{
    setSystemName(name);
    setCustomersArray(customers_array);
    setSellersArray(sellers_array);
    setCustomersArraySize(customer_array_size);
    setSellersArraySize(seller_array_size);
}
System::System(System &other)
{
    setSystemName(other.system_name);
    setCustomersArray(other.s_customers_array);
    setCustomersArraySize(other.customer_array_size);
    setSellersArray(other.s_sellers_array);
    setSellersArraySize(other.seller_array_size);
}
System::~System()
{
    for (int i = 0; i < customer_array_size; i++)
        delete s_customers_array[i];
    delete[] s_customers_array;
    for (int i = 0; i < seller_array_size; i++)
        delete s_sellers_array[i];
    delete[] s_sellers_array;
}
bool System::setSystemName(const char *given_system_name)
{
    system_name = new char[strlen(given_system_name) + 1];
    strcpy(system_name, given_system_name);
    return true;
}
bool System::setCustomersArray(const Customer **given_customer_array)
{
    s_customers_array = new Customer *[customer_array_size];
    for (int i = 0; i < customer_array_size; i++)
    {
        s_customers_array[i] = new Customer(*given_customer_array[i]);
    }
    return true;
}
bool System::setCustomersArraySize(const unsigned int newSize)
{
    customer_array_size = newSize;
    return true;
}
bool System::setSellersArray(const Seller **given_sellers_array)
{
    s_sellers_array = new Seller *[seller_array_size];
    for (int i = 0; i < seller_array_size; i++)
        s_sellers_array[i] = new Seller(*given_sellers_array[i]);
    return true;
}
bool System::setSellersArraySize(const unsigned int newSize)
{
    seller_array_size = newSize;
    return true;
}

char *System::getSystemName()
{
    return system_name;
}
Customer **System::getCostumeArray()
{
    return s_customers_array;
}
Seller **System::getSellersArray()
{
    return s_sellers_array;
}
int System::getSellersArraySize()
{
    return seller_array_size;
}
int System::getCustomerArraySize()
{
    return customer_array_size;
}
