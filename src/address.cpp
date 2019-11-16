#include "../include/address.h"

Address::Address(const char *cityName, const char *streetName, unsigned int apartmentNumber)
{
    setCityName(cityName);
    setStreetName(streetName);
    setApartmentNumber(apartmentNumber);
}
Address::Address(const Address &other)
{
    setStreetName(other.streetName);
    setApartmentNumber(other.apartmentNumber);
    setStreetName(other.streetName);
}
Address::~Address()
{
    delete[] cityName;
    delete[] streetName;
}
bool Address::setCityName(const char *givenCityName)
{
    cityName = new char[(strlen(givenCityName) + 1)];
    strcpy(cityName, givenCityName);
    return true;
}
bool Address::setStreetName(const char *givenStreetName)
{
    streetName = new char[(strlen(givenStreetName) + 1)];
    strcpy(streetName, givenStreetName);
    return true;
}
bool Address::setApartmentNumber(unsigned int givenApartmentNumber)
{
    if (givenApartmentNumber != 0) //the num is must be positive because of that it is unsigned.
    {
        apartmentNumber = givenApartmentNumber;
        return true;
    }
    else
        return false;
}
const char *Address::getCityName() const
{
    return cityName;
}
const char *Address::getStreetName() const
{
    return streetName;
}
unsigned int Address::getApartmentNumber() const
{
    return apartmentNumber;
}
