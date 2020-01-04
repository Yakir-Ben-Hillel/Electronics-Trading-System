#ifndef __ADDRESS_H
#define __ADDRESS_H
#include "system.h"
class Address
{
public:
    Address(unsigned int ApartmentNumber = 0, const char *cityName = nullptr,
            const char *streetName = nullptr) noexcept(false);
    Address(const Address &other);
    Address(Address &&other);
    ~Address();
    bool setCityName(const char *cityName);
    bool setStreetName(const char *streetName);
    bool setApartmentNumber(unsigned int apartmentNumber);
    const Address &operator=(const Address &other);
    const char *getCityName() const;
    const char *getStreetName() const;
    unsigned int getApartmentNumber() const;
    friend ostream &operator<<(ostream &out, const Address &address);
    friend istream &operator>>(istream &out, Address &address);

private:
    char *cityName;
    char *streetName;
    unsigned int apartmentNumber;
};
#endif
