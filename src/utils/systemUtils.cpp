#include "../../include/system.h"
void mainMenu();

void printOpening()
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
    cout << endl;
}
void printOptions()
{
    cout << "1) Add a Customer." << endl;
    cout << "2) Add a Seller." << endl;
    cout << "3)Add an new product to a Seller." << endl;
    cout << "4) Add a Feedback to a Seller." << endl;
    cout << "5) Add a Product to a Customer Wishlist." << endl;
    cout << "Please insert the number of your chosen option" << endl;
}
Address *makeAddress();
void mainMenu(System *system)
{
    printOptions();
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
    cin.ignore(256, '\n');
    new_address = new Address(apartment_number, city_name, street_name);
    return new_address;
}
Seller *System::makeSeller()
{
    Seller *new_seller = nullptr;
    Address *address = nullptr;
    char username[11], password[11];
    cout << "Please choose an username: ";
    cin.getline(username, 10);
    cout << "Please choose a password: ";
    cin.getline(password, 10);
    address = makeAddress();
    new_seller = new Seller(username, address, password);
    return new_seller;
}
void System::makeProductForSale()
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
        printSellersNames();
        cout << "Please choose yourself from the given list: ";
        cin >> seller_index;
        cin.ignore(256, '\n');
        seller_index--;
        Seller **sellers_array = this->getSellersArray();
        seller_of_product = sellers_array[seller_index];
    } while (!(seller_index <= this->getSellersArraySize() && seller_index >= 0));
    new_product = new Product(product_name, category, seller_of_product, UUID, price);
    UUID++;
    seller_of_product->addProductToStockArray(new_product);
}
Customer *System::makeCustomer()
{
    int x;
    Customer *new_customer;
    Address *address;
    char username[11], password[11];
    cout << "Please choose an username: ";
    cin.getline(username, 10);
    cout << "Please choose a password: ";
    cin.getline(password, 10);
    address = makeAddress();
    new_customer = new Customer(username, password, address);
    return new_customer;
}
void System::printCustomersNames()
{
    unsigned int index = 1;
    Customer **customer_array = this->getCostumeArray();
    for (int i = 0; i < this->getCustomerArraySize(); i++)
    {
        char name[11];
        strcpy(name, customer_array[i]->getName());
        printf("%d) %s\n", index, name);
        index++;
    }
}
void System::chooseProductToAddToCustomerWishlist()
{
    unsigned int customer_index, seller_index, product_index;
    Seller **sellers_array = this->getSellersArray();
    Product **product_array = nullptr;
    Customer **customers_array = this->getCostumeArray();
    do
    {
        printCustomersNames();
        cout << "Please choose the customer you want to use: ";
        cin >> customer_index;
        customer_index--;
    } while (!(customer_index <= this->getCustomerArraySize() && customer_index >= 0));

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
    customers_array[customer_index]->addProductToWishlistArray(product_array[product_index]);
}
void System::printSellersNames()
{
    unsigned int index = 1;
    Seller **sellers_array = this->getSellersArray();
    for (int i = 0; i < this->getSellersArraySize(); i++)
    {
        char name[11];
        strcpy(name, sellers_array[i]->getUserName());
        printf("%d) %s\n", index, name);
        index++;
    }
}
void Seller::printSellerProducts()
{
    int length = this->getStockArraySize();
    Product **products_array = this->getStock();
    Product *product = nullptr;
    for (int i = 0; i < length; i++)
    {
        product = products_array[i];
        printf("%d) %s", i + 1, product->getName());
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