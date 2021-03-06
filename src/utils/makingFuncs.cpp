#include "../../include/system.h"
Address *System::makeAddress() noexcept(false)
{
    Address *new_address = nullptr;
    string city_name, street_name;
    int apartment_number;
    cout << "Please insert your city name: ";
    getline(cin, city_name);
    cout << "Please insert your street name: ";
    getline(cin, street_name);
    cout << "Please insert your apartment number:";
    cin >> apartment_number;

    new_address = new Address(apartment_number, city_name, street_name);
    return new_address;
}
void Seller::makeProductForSale() noexcept(false)
{
    char x;
    Product::eCategory category;
    string product_name;
    float price;
    Seller *seller_of_product;
    unsigned int seller_index;
    bool isCategoryValid = false;
    cout << "Please follow the instruction to add your product to the system." << endl;
    cout << "Please choose a name: ";
    cin.ignore(256, '\n');
    getline(cin, product_name);
    while (!isCategoryValid)
    {
        isCategoryValid = true;
        cout << "1) Children" << endl
             << "2) Electricity" << endl
             << "3) Office" << endl
             << "4) Clothing" << endl;
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
    Product *new_product = new Product(product_name, category, *this, price);
    this->addProductToStockArray(*new_product);
    cout << "Product added successfully to the system!" << endl;
}
void System::chooseProductToAddToCustomerWishlist()
{
    Customer *customerTemp = dynamic_cast<Customer *>(this->logged_in_user);
    Seller *sellerTemp = nullptr;
    int seller_index, product_index;
    if (customerTemp) //Double check.
    {
        vector<int> indexes_array;
        int available_index_counter = 0;
        vector<Product *> product_array;
        vector<User *>::iterator itr = this->users_array.begin();
        vector<User *>::iterator itrEnd = this->users_array.end();
        for (int i = 0; itr != itrEnd; ++itr, i++)
        {
            sellerTemp = dynamic_cast<Seller *>(*itr);
            if (sellerTemp && (customerTemp->getName().compare(sellerTemp->getName())) != 0)
            {
                if (!sellerTemp->getStock().empty())
                {
                    indexes_array.push_back(i);
                    available_index_counter++;
                }
            }
        }
        if (available_index_counter != 0)
        {
            bool toContinue = false;
            do
            {
                do
                {
                    for (int i = 0; i < available_index_counter; i++)
                    {
                        cout << i + 1 << ")" << (*(this->users_array.begin() + *(indexes_array.begin() + i)))->getName() << endl;
                    }
                    cout <<endl<< "Please choose a seller in-order to view his products: ";
                    cin >> seller_index;
                    seller_index--;
                } while (!(seller_index <= available_index_counter && seller_index >= 0));
                Seller *chosen_seller = dynamic_cast<Seller *>(this->users_array[indexes_array[seller_index]]);
                if (chosen_seller)
                {
                    do
                    {
                        chosen_seller->printSellerProducts();
                        cout << endl
                             << "Please choose the product you want to add into your wishlist: ";
                        cin >> product_index;
                        product_index--;
                    } while (!(product_index <= chosen_seller->getStock().size() && product_index >= 0));
                    product_array = chosen_seller->getStock();
                    vector<Product *>::iterator itr = ((product_array.begin()) + product_index);
                    customerTemp->addProductToWishlistArray(*(*itr));
                    cout << "Would you like to continue adding Products to the Wishlist? (y/n): ";
                    char answer;
                    cin >> answer;
                    answer == 'y' ? toContinue = true : toContinue = false;
                }
            } while (toContinue);
        }
        else
        {
            cout << "No Sellers to choose Products from." << endl;
        }
    }
}
bool System::addFeedback(Customer &customer) noexcept(false)
{
    vector<int> indexes_array;
    int x;
    Seller *seller_temp = nullptr;
    vector<User *>::iterator itr = this->users_array.begin();
    vector<User *>::iterator itrEnd = this->users_array.end();
    for (int i = 0; itr != itrEnd; ++itr, i++)
    {
        seller_temp = dynamic_cast<Seller *>(*itr);
        if (seller_temp)
            if (customer.didCustomerOrderedFromSeller(*seller_temp))
            {
                indexes_array.push_back(i);
            }
    }
    if (!indexes_array.empty())
    {
        this->printAllAvailableSellersToGiveFeedbacks(customer);
        cout << "Please insert the number of the seller you want to leave a feedback on: ";
        cin >> x;
        x--;
        seller_temp = dynamic_cast<Seller *>(this->users_array[indexes_array[x]]);
        if (seller_temp)
        {
            customer.addFeedBackToSeller(*seller_temp);
            return true;
        }
        else
            return false;
    }
    else
    {
        cout << "No sellers to add Feedbacks to." << endl;
        cout << "Make an Order and checkback later." << endl;
        return false;
    }
}
void System::signup()
{
    User *user = nullptr;
    Address *address = nullptr;
    unsigned int chosen_type;
    do
    {
        cout << "What do you want to signup as?" << endl;
        cout << "1) Customer" << endl;
        cout << "2) Seller" << endl;
        cout << "3) Customer And Seller" << endl;
        cin >> chosen_type;
        cin.ignore(256, '\n');
        if (chosen_type < 1 || chosen_type > 3)
            cout << "Input invalid please try again." << endl;
    } while (chosen_type < 1 || chosen_type > 3);
    bool availabilty = true;
    bool check = true;
    do
    {
        string username, password;
        do
        {
            cout << "Please choose an username: ";
            getline(cin, username);
            if (checkUsernameAvailability(username) == false)
            {
                cout << "Username is not available, please choose another name." << endl;
                availabilty = false;
            }
            else
                availabilty = true;
        } while (availabilty == false);
        cout << "Please choose a password: ";
        getline(cin, password);
        check = true;
        try
        {
            address = makeAddress();
        }
        catch (const AddressException &a)
        {
            check = false;
            a.show();
            cin.ignore(256, '\n');
        }
        if (check != false) //if check==false we want that the loop to end so the yser will try to put the address from the start
        {
            //we dont have to delete the username and password because they are statics and not allocated
            switch (chosen_type)
            {
            case 1:
                try
                {
                    user = new Customer(username, password, *address);
                }
                catch (const UserException &e)
                {
                    check = false;
                    delete address; //we should delete the allocated address cause there was a problem with the user allocation
                    e.show();
                    cin.ignore(256, '\n');
                }
                break;
            case 2:
                try
                {
                    user = new Seller(username, password, *address);
                }
                catch (const UserException &e)
                {
                    check = false;
                    delete address; //we should delete the allocated address cause there was a problem with the user allocation
                    e.show();
                    cin.ignore(256, '\n');
                }
                break;
            case 3:
                try
                {
                    user = new CAS(username, password, *address);
                }
                catch (const UserException &e)
                {
                    check = false;
                    delete address; //we should delete the allocated address cause there was a problem with the user allocation
                    e.show();
                    cin.ignore(256, '\n');
                }
                break;
            default:
                break;
            }
        }
    } while (!check);
    *this += user;
    cout << endl
         << "User added successfully, please enjoy your using on our trade system!" << endl;
}
