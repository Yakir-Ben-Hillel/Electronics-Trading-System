#include "../../include/system.h"

void System::mainMenu()
{
    bool isFinished = false;
    unsigned int option;
    printOpening();
    while (!isFinished)
    {
        if (this->logged_in_customer == nullptr && this->logged_in_seller == nullptr)
        { //Both are nullptr.
            printOptionsAsGuest();
            cin >> option;
            switch (option)
            {
            case 1:
                this->login();
                break;
            case 2:
                this->signup();
                break;
            case 3:
                this->printCustomersNames();
                break;
            case 4:
                this->printSellersNames();
                break;
            case 5:
                isFinished = true;
                break;
            default:
                break;
            }
        }
        else if (this->logged_in_customer != nullptr)
        {
            printOptionsAsCustomer();
            cin >> option;
            switch (option)
            {
            case 1:
                this->chooseProductToAddToCustomerWishlist();
                break;
            case 2:
                int x;
                this->printAllAvailableSellersToGiveFeedbacks(this->logged_in_customer);
                cout << "Please insert the number of the seller you want to leave a feedback on: ";
                cin >> x;
                this->logged_in_customer->addFeedBackToSeller(this->s_sellers_array[x - 1]);
                break;
            case 3:
                this->logged_in_customer->makeOrder();
                break;
            case 4:
                this->printSellersNames();
                break;
            case 5:
                cout << "Please insert the name of the product you want to search for: ";
                char name[11];
                cin.getline(name, 10);
                this->showProductsWithTheSameName(name);
                break;
            case 6:
                logged_in_customer = nullptr;
                break;
            case 7:
                isFinished = true;
                break;
            default:
                break;
            }
        }
        else
        {
            printOptionsAsSeller();
            cin >> option;
            switch (option)
            {
            case 1:
                this->logged_in_seller->makeProductForSale();
                break;
            case 2:
                /*this->printFeedbacks()*/
                break;
            case 3:
                this->logged_in_seller = nullptr;
                break;
            case 4:
                isFinished = true;
                break;
            default:
                break;
            }
        }
    }
}

Address *System::makeAddress()
{
    Address *new_address = nullptr;
    char city_name[11], street_name[31];
    int apartment_number;
    cout << "Please insert your city name: ";
    cin.getline(city_name, 10);
    cout << "Please insert your street name :";
    cin.getline(street_name, 30);
    cout << "Please insert your apartment number :";
    cin >> apartment_number;
    cin.ignore(256, '\n');
    new_address = new Address(apartment_number, city_name, street_name);
    return new_address;
}
void System::makeSeller()
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
    this->addSellerToArray(new_seller);
}
void Seller::makeProductForSale()
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
    new_product = new Product(product_name, category, this,price);
    this->addProductToStockArray(new_product);
}
void System::makeCustomer()
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
    this->addCustomerToArray(new_customer);
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
void System::login()
{
    unsigned int chosen_type;
    do
    {
        cout << "Are you a Customer or a Seller?" << endl;
        cout << "1) Customer" << endl;
        cout << "2) Seller" << endl;
        cin >> chosen_type;
        cin.ignore(256, '\n');
        if (chosen_type < 1 || chosen_type > 2)
            cout << "Input invalid please try again." << endl;
    } while (chosen_type < 1 || chosen_type > 2);
    if (chosen_type == 1)
        customerLogin();
    else
        sellerLogin();
}
void System::signup()
{
    unsigned int chosen_type;
    do
    {
        cout << "What do you want to signup as?" << endl;
        cout << "1) Customer" << endl;
        cout << "2) Seller" << endl;
        cin >> chosen_type;
        cin.ignore(256, '\n');
        if (chosen_type < 1 || chosen_type > 2)
            cout << "Input invalid please try again." << endl;
    } while (chosen_type < 1 || chosen_type > 2);
    if (chosen_type == 1)
        this->makeCustomer();
    else
        this->makeSeller();
}
void System::customerLogin()
{
    if (this->customer_array_logical_size != 0)
    {
        char username[11], password[11];
        cout << "Please enter your Username" << endl;
        cin.getline(username, 10);
        int i = 0;
        bool isFinishedSearch = false;
        while (isFinishedSearch == false || i != this->customer_array_logical_size)
        {
            if (strcmp(s_customers_array[i]->getName(), username) == 0)
            {
                bool isMatch = false;
                bool isExitedByWill = false;

                isFinishedSearch = true;
                do
                {
                    cout << "Please insert your Password, write 'back' in any given time to go main menu." << endl;
                    cin.getline(password, 10);
                    if (strcmp(password, "back") == 0)
                        isExitedByWill = true;
                    else if (strcmp(password, s_customers_array[i]->getPassWord()) == 0)
                    {
                        this->logged_in_customer = s_customers_array[i];
                        this->logged_in_seller = nullptr;
                        isMatch = true;
                    }
                    else
                    {
                        cout << "Password incorrect please try again." << endl;
                    }

                } while (isMatch == false && isFinishedSearch == false);
            }
            i++;
        }
    }
    else
    {
        cout << "There are no Customers Available" << endl;
        system("pause");
    }
}
void System::sellerLogin()
{
    if (this->seller_array_logical_size != 0)
    {
        char username[11], password[11];
        cout << "Please enter your Username" << endl;
        cin.getline(username, 10);
        int i = 0;
        bool isFinishedSearch = false;
        while (isFinishedSearch == false && i != this->seller_array_logical_size)
        {
            if (strcmp(s_sellers_array[i]->getUserName(), username) == 0)
            {
                bool isMatch = false;
                bool isExitedByWill = false;

                isFinishedSearch = true;
                do
                {
                    cout << "Please insert your Password, write 'back' in any given time to go main menu." << endl;
                    cin.getline(password, 10);
                    if (strcmp(password, "back") == 0)
                        isExitedByWill = true;
                    else if (strcmp(password, s_sellers_array[i]->getPassword()) == 0)
                    {
                        this->logged_in_seller = s_sellers_array[i];
                        this->logged_in_customer = nullptr;
                        isMatch = true;
                    }
                    else
                    {
                        cout << "Password incorrect please try again." << endl;
                    }

                } while (isMatch == false && isFinishedSearch == false);
            }
            i++;
        }
    }
    else
    {
        cout << "There are no Sellers Available" << endl;
    }
}

void System::showProductsWithTheSameName(const char *name)
{
    cout << "The Products you have searched for ,show to you below: " << endl;
    for (int i = 0; i < this->seller_array_logical_size; i++)
    {
        int size = this->s_sellers_array[i]->getStockArraySize();
        Product **stock = this->s_sellers_array[i]->getStock();
        for (int j = 0; j < size; j++)
        {
            if (strcmp(name, stock[j]->getName()) == 0)
            {
                stock[j]->printProduct();
                cout << endl;
            }
        }
    }
}