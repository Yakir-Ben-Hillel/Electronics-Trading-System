#include "../include/system.h"

void mainMenu();
void printOptions();
Seller *makeSeller();
void printOptions()
{
    cout << "***************************************" << endl;
    cout << "***************************************" << endl;
    cout << " #########   ##    ##    ########     ########" << endl;
    cout << "##           ##    ##   ##      ##    ##    ##" << endl;
    cout << " ##          ##    ##  ##        ##   ##   ##" << endl;
    cout << " #########   ########  ##        ##   ######" << endl;
    cout << "        ##   ##    ##   ##      ##    ##" << endl;
    cout << "       ##    ##    ##    ########     ##" << endl;
    cout << " #######     ##    ##                 ##" << endl;
    cout << "*****************************************" << endl;
    cout << "*****************************************" << endl;
    cout << endl
         << "Please insert the number of your chosen option" << endl;
    cout << "1) Add a Customer." << endl;
    cout << "2) Add a Seller." << endl;
    cout << "3)Add an new product to a Seller." << endl;
    cout << "4) Add a Feedback to a Seller." << endl;
    cout << "5) Add a Product to a Customer Wishlist." << endl;
}
Address *makeAddress();
void mainMenu()
{
    // printOptions();
    bool isFinished = false;
}
Address *makeAddress()
{
    Address *new_address = nullptr;
    char city_name[11], street_name[21];
    int apartment_number;
    cout << "Please insert your city name: ";
    cin.getline(city_name, 10);
    cout << "Please insert your street name :";
    cin.getline(street_name, 20);
    cout << "Please insert your apartment number :";
    cin >> apartment_number;
    new_address = new Address(apartment_number, city_name, street_name);
    return new_address;
}
Seller *makeSeller()
{
    Seller *new_seller;
    Address *address;
    char username[11], password[11];
    cout << "Please choose an username: ";
    cin.getline(username, 10);
    cout << "Please choose a password: ";
    cin.getline(password, 10);
    address = makeAddress();
    new_seller = new Seller(username, address, password);
    return new_seller;
}
// void resize() {
//     size_t newSize = size * 2;
//     int* newArr = new int[newSize];

//     memcpy( newArr, arr, size * sizeof(int) );

//     size = newSize;
//     delete [] arr;
//     arr = newArr;
// }
//Resize algorithm structure.