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
void System::chooseProductToAddToCustomerWishlist()
{
    Customer *customerTemp = dynamic_cast<Customer *>(this->logged_in_user);
    User *sellerTemp = nullptr;
    int seller_index, product_index;
    if (customerTemp) //Double check.
    {
        int indexes_array[this->users_array_logical_size];
        int available_index_counter = 0;
        Product **product_array = nullptr;
        for (int i = 0; i < users_array_logical_size; i++)
        {
            sellerTemp = dynamic_cast<Seller *>(this->users_array[i]);
            if (sellerTemp)
                indexes_array[available_index_counter] = i;
        }
        do
        {
            printSellersNames();
            cout << "Please choose a seller in-order to view his products: ";
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
            } while (!(product_index <= chosen_seller->getStockArraySize() && product_index >= 0));
            product_array = chosen_seller->getStock();
            customerTemp->addProductToWishlistArray(product_array[product_index]);
        }
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
