#include "../../include/system.h"

Address::Address(unsigned int apartmentNumber, const string &cityName, const string &streetName) noexcept(false) : apartmentNumber(apartmentNumber)
{
    if (apartmentNumber <= 0 || cityName.empty() || streetName.empty())
    {
        this->apartmentNumber = 0; //in case that the updated apartment number was negative.
        throw AddressException(apartmentNumber, streetName, cityName);
    }
    this->setCityName(cityName);
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
const Address &Address::operator=(const Address &other)
{
    if (this != &other)
    {
        this->setCityName(other.cityName);
        this->setStreetName(other.streetName);
        this->setApartmentNumber(other.apartmentNumber);
    }
    return *this;
}
void Address::setCityName(const string &givenCityName)
{
    this->cityName = givenCityName;
}
void Address::setStreetName(const string &givenStreetName)
{
    this->streetName = givenStreetName;
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
const string &Address::getCityName() const
{
    return cityName;
}
const string &Address::getStreetName() const
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
        out << address.cityName << " " << address.streetName << " " << address.apartmentNumber << " " << endl;
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
    string cityName, streetName;
    in >> cityName >> streetName >> address.apartmentNumber;
    address.setCityName(cityName);
    address.setStreetName(streetName);
    return in;
}