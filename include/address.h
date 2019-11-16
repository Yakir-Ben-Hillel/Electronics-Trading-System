#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <iostream>
#include <string.h>
using namespace std;
class Address
{
public:
    Address() = default;
    Address(const char* cityName ,const char *streetName,unsigned int ApartmentNumber);
    Address(const Address &other);
    ~Address();
    bool setCityName(const char *cityName);
    bool setStreetName(const char *streetName);
    bool setApartmentNumber(unsigned int apartmentNumber);
    
    const char *getCityName() const;
    const char *getStreetName() const;
    unsigned int getApartmentNumber() const;

private:
    char *cityName;
    char *streetName;
    unsigned int apartmentNumber;
};
#endif
