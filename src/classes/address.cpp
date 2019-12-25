#include "../../include/system.h"

Address::Address(unsigned int apartmentNumber, const char *cityName, const char *streetName)
{
    setCityName(cityName);
    setStreetName(streetName);
    setApartmentNumber(apartmentNumber);
}
Address::Address(const Address &other)
{
    setCityName(other.cityName);
    setApartmentNumber(other.apartmentNumber);
    setStreetName(other.streetName);
}
Address::Address(Address &&other)
{
    cityName = other.cityName;
    streetName = other.streetName;
    apartmentNumber = other.apartmentNumber;

    other.cityName = nullptr;
    other.streetName = nullptr;
}
Address::~Address()
{
    delete[] cityName;
    delete[] streetName;
}
const Address &Address::operator=(const Address &other)
{
    if (this != &other)
    {
        delete[] cityName;
        this->setCityName(other.cityName);
        delete[] streetName;
        this->setStreetName(other.streetName);
        this->setApartmentNumber(other.apartmentNumber);
    }
    return *this;
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
    if (givenApartmentNumber > 0) //the number is must be positive because it is unsigned.
    {
        apartmentNumber = givenApartmentNumber;
        return true;
    }
    cout << "apartment number must be positive" << endl;
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

ostream &operator<<(ostream &out, const Address &address)
{
    out << address.cityName << " " << address.streetName << " " << address.apartmentNumber << " " << endl;
    return out;
}
istream &operator>>(istream &in, Address &address)
{
    in >> address.cityName >> address.streetName >> address.apartmentNumber;
    return in;
}