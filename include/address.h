#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
using namespace std;
#include <string>
#include <exception>
#include <fstream>
#include <vector>
class Address
{
public:
    Address() = default;
    Address(unsigned int ApartmentNumber, const string &cityName,
            const string &streetName) noexcept(false);
    Address(const Address &other);
    Address(Address &&other);
    ~Address(){};
    void setCityName(const string &cityName);
    void setStreetName(const string &streetName);
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
