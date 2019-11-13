#include "../include/system.h"
System::System(const char *name, Costumer **costumers_array, Seller **sellers_array, unsigned int costumers_array_size = 0, unsigned int sellers_array_size = 0)
{
    setSystemName(name);
    setCostumersArray(costumers_array);
    setSellersArray(sellers_array);
    setCostumersArraySize(costumer_array_size);
    setSellersArraySize(seller_array_size);
}
System::System(System &other)
{
    setSystemName(other.system_name);
    setCostumersArray(other.s_costumers_array);
    setCostumersArraySize(other.costumer_array_size);
    setSellersArray(other.s_sellers_array);
    setSellersArraySize(other.seller_array_size);
}
System::~System()
{
    for (int i = 0; i < costumer_array_size; i++)
        delete s_costumers_array[i];
    delete[] s_costumers_array;
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
bool System::setCostumersArray(const Costumer **given_costumer_array)
{
    s_costumers_array = new Costumer *[costumer_array_size];
    for (int i = 0; i < costumer_array_size; i++)
    {
        s_costumers_array[i] = new Costumer(*given_costumer_array[i]);
    }
    return true;
}
bool System::setCostumersArraySize(const unsigned int newSize)
{
    costumer_array_size = newSize;
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
Costumer **System::getCostumeArray()
{
    return s_costumers_array;
}
Seller **System::getSellersArray()
{
    return s_sellers_array;
}
int System::getSellersArraySize()
{
    return seller_array_size;
}
int System::getCostumerArraySize()
{
    return costumer_array_size;
}
