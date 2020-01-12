#ifndef __ADDRESS_H
#define __ADDRESS_H
#include "system.h"
class Address
{
public:
    Address() = default;
    Address(unsigned int ApartmentNumber, const string &cityName,
            const string &streetName) noexcept(false);
    Address(const Address &other);
    Address(Address &&other);
    ~Address();
    bool setCityName(const string &cityName);
    bool setStreetName(const string &streetName);
    bool setApartmentNumber(unsigned int apartmentNumber);
    const Address &operator=(const Address &other);
    const string &getCityName() const;
    const string &getStreetName() const;
    unsigned int getApartmentNumber() const;
    friend ostream &operator<<(ostream &out, const Address &address);
    friend istream &operator>>(istream &out, Address &address);

private:
    string cityName;
    string streetName;
    unsigned int apartmentNumber;
};
#endif
