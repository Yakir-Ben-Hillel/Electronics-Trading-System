#include "../include/system.h"

void mainMenu();
void printOptions();
void printSellersNames(System *system);
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
void makeProduct(System *system)
{
    char x;
    Product *new_product;
    Product::eCategory category;
    char product_name[11];
    float price;
    Seller *seller_of_product;
    unsigned int serialNumber;
    unsigned int seller_index;
    bool isCategoryValid = false;
    cout << "Please choose a name: ";
    cin >> x;
    cin.getline(product_name, 10);
    while (!isCategoryValid)
    {
        isCategoryValid = true;
        cout << "1) Children" << endl
             << "2) Electricity" << endl
             << "3) Office" << endl
             << "4)Clothing" << endl;
        cout << "Please insert the number of your product category: ";
        int chosen;
        cin >> chosen;
        switch (chosen)
        {
        case 1:
            category = Product::Children;
            isCategoryValid = true;
            break;
        case 2:
            category = Product::Electricity;
            isCategoryValid = true;
            break;
        case 3:
            category = Product::Office;
            isCategoryValid = true;
            break;
        case 4:
            category = Product::Clothing;
            isCategoryValid = true;
            break;
        default:
            cout << "Inserted number is not valid please try again." << endl;
            isCategoryValid = false;
            break;
        }
    }
    cout << "Please choose a price for your product: ";
    cin >> price;
    do
    {
        printSellersNames(system);
        cout << "Please choose yourself from the given list: ";
        cin >> seller_index;
        seller_index--;
        Seller **sellers_array = system->getSellersArray();
        seller_of_product = sellers_array[seller_index];
    } while (!(seller_index <= system->getSellersArraySize() && seller_index >= 0));
    new_product = new Product(product_name, category, seller_of_product, UUID, price);
    UUID++;
    seller_of_product->addProductToStockArray(new_product);
}

void printSellersNames(System *system)
{
    int index = 1;
    Seller **sellers_array = system->getSellersArray();
    for (int i = 0; i < system->getSellersArraySize(); i++)
    {
        char name[11];
        strcpy(name, sellers_array[i]->getUserName());
        printf("%d) %s\n", index, name);
        index++;
    }
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