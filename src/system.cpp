#include "../include/system.h"
System::System(const char *name, Customer **customers_array, Seller **sellers_array,
               unsigned int customers_array_physical_size,
               unsigned int customers_array_logical_size,
               unsigned int sellers_array_physical_size,
               unsigned int sellers_array_logical_size)
{
    setSystemName(name);
    setCustomersArray((const Customer **)customers_array);
    setSellersArray((const Seller **)sellers_array);
    setCustomersArrayPhysicalSize(customers_array_physical_size);
    setSellersArrayPhysicalSize(sellers_array_physical_size);
}
System::System(const System &other)
{
    setSystemName(other.system_name);
    setCustomersArray((const Customer **)other.s_customers_array);
    setCustomersArrayPhysicalSize(other.customer_array_logical_size);
    setSellersArray((const Seller **)other.s_sellers_array);
    setSellersArrayPhysicalSize(other.seller_array_logical_size);
}
System::~System()
{
    for (int i = 0; i < customer_array_logical_size; i++)
        delete s_customers_array[i];
    delete[] s_customers_array;
    for (int i = 0; i < seller_array_logical_size; i++)
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
    s_customers_array = new Customer *[customer_array_logical_size];
    for (int i = 0; i < customer_array_logical_size; i++)
    {
        s_customers_array[i] = new Customer(*given_customer_array[i]);
    }
    return true;
}
bool System::setCustomersArrayPhysicalSize(const unsigned int newSize)
{
    customer_array_physical_size = newSize;
    return true;
}
bool System::setCustomersArrayLogicalSize(const unsigned int newSize)
{
    customer_array_logical_size = newSize;
    return true;
}

bool System::setSellersArray(const Seller **given_sellers_array)
{
    s_sellers_array = new Seller *[seller_array_logical_size];
    for (int i = 0; i < seller_array_logical_size; i++)
        s_sellers_array[i] = new Seller(*given_sellers_array[i]);
    return true;
}
bool System::setSellersArrayPhysicalSize(const unsigned int newSize)
{
    seller_array_physical_size = newSize;
    return true;
}
bool System::setSellersArrayLogicalSize(const unsigned int newSize)
{
    seller_array_logical_size = newSize;
    return true;
}

bool System::addSellerToArray(Seller *newSeller)
{
    if (this->seller_array_logical_size == this->seller_array_physical_size)
        resizeSellersArray();
    s_sellers_array[seller_array_logical_size] = newSeller;
    seller_array_logical_size++;
}
void System::resizeSellersArray()
{
    int newSize = this->seller_array_physical_size * 2 + 1;
    Seller **newArray = new Seller *[newSize];
    memcpy(newArray, this->s_sellers_array, this->seller_array_logical_size * sizeof(Seller *));
    for (int i = 0; i < this->seller_array_logical_size; i++)
        delete this->s_sellers_array[i];
    delete[] this->s_sellers_array;
    this->seller_array_physical_size = newSize;
    this->s_sellers_array = newArray;
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
    return seller_array_logical_size;
}
int System::getCustomerArraySize()
{
    return customer_array_logical_size;
}
