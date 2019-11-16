#ifndef __ADDRESS
#define __ADDRESS
#include "system.h"
class Address
{
public:
    Address() = default;
    Address(char *streetName, int ApartmentNumber, int zip = NULL);
    Address(const Address &other);
    ~Address();
    bool setCityName(char *cityName);
    bool setStreetName(char *streetName);
    bool setApartmentNumber(int apartmentNumber);
    bool setZIP(int zip);
    char *getCityName() const;
    char *getStreetName() const;
    int getApartmentNumber() const;
    int getZIP() const;

private:
    char *cityName;
    char *streetName;
    int apartmentNumber;
    int zip = NULL;
};
#endif //!__ADDRESS
