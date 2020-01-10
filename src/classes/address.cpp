#include "../../include/system.h"

Address::Address(unsigned int apartmentNumber, const char *cityName, const char *streetName) noexcept(false) : apartmentNumber(apartmentNumber)
{
    if (apartmentNumber <= 0 || strcmp(cityName, "") == 0 || strcmp(streetName, "") == 0)
    {
        this->apartmentNumber = 0; //in case that the updated apartment number was negative.
        throw AddressException(apartmentNumber, streetName, cityName);
    }
    if (cityName)
        this->setCityName(cityName);
    if (streetName)
        this->setStreetName(streetName);
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
    if (typeid(out) == typeid(ofstream))
    {
        out << address.cityName << " " << address.streetName << " "<<address.apartmentNumber << " " << endl;
    }
    else
    {
        out << "City Name: " << address.cityName << endl;
        out << "Street Name: " << address.streetName << endl;
        out << "Apartment Number: " << address.apartmentNumber << endl;
    }
    return out;
}
istream &operator>>(istream &in, Address &address)
{
    char cityName[11], streetName[21];
    in >> cityName >> streetName >> address.apartmentNumber;
    address.setCityName(cityName);
    address.setStreetName(streetName);
    return in;
}