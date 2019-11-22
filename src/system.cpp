#include "../include/system.h"
System::System(Customer **customers_array, Seller **sellers_array,
               unsigned int customers_array_physical_size,
               unsigned int customers_array_logical_size,
               unsigned int sellers_array_physical_size,
               unsigned int sellers_array_logical_size)
{
    setCustomersArray((const Customer **)customers_array);
    setSellersArray((const Seller **)sellers_array);
    setCustomersArrayPhysicalSize(customers_array_physical_size);
    setSellersArrayPhysicalSize(sellers_array_physical_size);
}
System::System(const System &other)
{
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
    return true;
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
bool System::addCustomerToArray(Customer *newCustomer)
{
    if (this->customer_array_logical_size == this->customer_array_physical_size)
        resizeCustomersArray();
    s_customers_array[customer_array_logical_size] = newCustomer;
    customer_array_logical_size++;
    return true;
}
void System::resizeCustomersArray()
{
    int newSize = this->customer_array_physical_size * 2 + 1;
    Customer **newArray = new Customer *[newSize];
    memcpy(newArray, this->s_customers_array, this->customer_array_logical_size * sizeof(Seller *));
    for (int i = 0; i < this->customer_array_logical_size; i++)
        delete this->s_customers_array[i];
    delete[] this->s_customers_array;
    this->customer_array_physical_size = newSize;
    this->s_customers_array = newArray;
}

const char *System::getSystemName() const
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
