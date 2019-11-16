#include "../include/system.h"
Seller addSeller()
{
    Seller seller;
    char name[20];
    char city[20];
    Address address;
    int apartment;
    cout << "Hello, what is your name?" << endl;
    cin.getline(name, 20);
    cout << "Please insert the city you are currently living at:" << endl;
    cin.getline(city, 20);
    address.setCityName(city);
    cout << "Please enter your apartment number:" << endl;
    cin >> apartment;
    address.setApartmentNumber(apartment);
    seller.setAddress(address);
    return seller;
}