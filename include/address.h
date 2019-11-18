#ifndef __ADDRESS_H
#define __ADDRESS_H

class Address
{
public:
    Address() = default;
    Address(unsigned int ApartmentNumber, const char *cityName = nullptr, const char *streetName = nullptr);
    Address(const Address &other);
    Address(Address &&other);
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
