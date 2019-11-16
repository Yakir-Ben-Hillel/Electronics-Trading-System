#include "../include/address.h"

Address::Address(char *streetName, int apartmentNumber, int zip = NULL)
{
    setStreetName(streetName);
    setApartmentNumber(apartmentNumber);
    if (zip)
        setZIP(zip);
}
Address::Address(const Address &other)
{
    setStreetName(other.streetName);
    setApartmentNumber(other.apartmentNumber);
    if (other.zip)
        setZIP(other.zip);
}
Address::~Address()
{
    delete streetName;
}
bool Address::setCityName(char *givenCityName)
{
    cityName = new char[(strlen(givenCityName) + 1)];
    return true;
}
bool Address::setStreetName(char *givenStreetName)
{
    streetName = new char[(strlen(givenStreetName) + 1)];
    return true;
}
bool Address::setApartmentNumber(int givenApartmentNumber)
{
    if (givenApartmentNumber != 0)
    {
        apartmentNumber = givenApartmentNumber;
        return true;
    }
    else
        return false;
}
bool Address::setZIP(int givenZIP)
{
    if (givenZIP != 0)
    {
        zip = givenZIP;
        return true;
    }
    else
        return false;
}
char *Address::getCityName() const
{
    return cityName;
}
char *Address::getStreetName() const
{
    return streetName;
}
int Address::getApartmentNumber() const
{
    return apartmentNumber;
}
int Address::getZIP() const
{
    return zip;
}