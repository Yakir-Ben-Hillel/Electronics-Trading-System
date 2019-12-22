#include "../../include/system.h"
Address *System::makeAddress()
{
    Address *new_address = nullptr;
    char city_name[11], street_name[21];
    int apartment_number;
    cout << "Please insert your city name (10 chars max): ";
    cin.getline(city_name, 10);
    cout << "Please insert your street name (20 chars max): ";
    cin.getline(street_name, 20);
    do
    {
        cout << "Please insert your apartment number :";
        cin >> apartment_number;
        cin.ignore(256, '\n');
        apartment_number < 0 && cout << ("invalid number, please try again") << endl;

    } while (apartment_number < 0);

    new_address = new Address(apartment_number, city_name, street_name);
    return new_address;
}
void System::makeSeller()
{
    Seller *new_seller = nullptr;
    Address *address = nullptr;
    bool availabilty = true;
    char username[11], password[11];
    do
    {
        cout << "Please choose an username (10 chars max): ";
        cin.getline(username, 10);
        if (checkUsernameAvailability(username) == false)
        {
            availabilty = false;
            cout << "Username is taken, please choose another name." << endl;
        }
        else
            availabilty = true;
    } while (availabilty == false);
    cout << "Please choose a password (10 chars max): ";
    cin.getline(password, 10);
    address = makeAddress();
    new_seller = new Seller(User(username, password, *address));
    this->addSellerToArray(new_seller);
}
void Seller::makeProductForSale()
{
    char x;
    Product *new_product;
    Product::eCategory category;
    char product_name[21];
    float price;
    Seller *seller_of_product;
    unsigned int seller_index;
    bool isCategoryValid = false;
    cout << "Please choose a name: (20 chars max)";
    cin.ignore(256, '\n');
    cin.getline(product_name, 20);
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
            cin.ignore(256, '\n');
            break;
        }
    }
    cout << "Please choose a price for your product: ";
    cin >> price;
    new_product = new Product(product_name, category, this, price);
    this->addProductToStockArray(new_product);
}
void System::makeCustomer()
{
    int x;
    Customer *new_customer;
    Address *address;
    bool availabilty = true;
    char username[11], password[11];
    do
    {
        cout << "Please choose an username (10 chars max): ";
        cin.getline(username, 10);
        if (checkUsernameAvailability(username) == false)
        {
            cout << "Username is not available, please choose another name." << endl;
            availabilty = false;
        }
        else
            availabilty = true;
    } while (availabilty == false);
    cout << "Please choose a password (10 chars max): ";
    cin.getline(password, 10);
    address = makeAddress();
    new_customer = new Customer(User(username, password, *address));
    this->addCustomerToArray(new_customer);
}
void System::chooseProductToAddToCustomerWishlist()
{
    if (this->logged_in_customer) //Double check.
    {
        unsigned int customer_index, seller_index, product_index;
        Seller **sellers_array = this->getSellersArray();
        Product **product_array = nullptr;
        do
        {
            printSellersNames();
            cout << "Please choose a seller in-order to view his products: ";
            cin >> seller_index;
            seller_index--;
        } while (!(seller_index <= this->getSellersArraySize() && seller_index >= 0));
        Seller *chosen_seller = sellers_array[seller_index];
        do
        {
            chosen_seller->printSellerProducts();
            cout << endl
                 << "Please choose the product you want to add into your wishlist: ";
            cin >> product_index;
            product_index--;
        } while (!(product_index <= chosen_seller->getStockArraySize() && product_index >= 0));
        product_array = chosen_seller->getStock();
        this->logged_in_customer->addProductToWishlistArray(product_array[product_index]);
    }
}
void System::makeOrder()
{
    unsigned int customer_index;
    Order *new_order = new Order();
    Product **product_array = nullptr;
    do
    {
        printCustomersNames();
        cout << "Please choose yourself from the list" << endl;
        cin >> customer_index;
        customer_index--;
    } while (!(customer_index <= this->getCustomerArraySize() && customer_index >= 0));
}
