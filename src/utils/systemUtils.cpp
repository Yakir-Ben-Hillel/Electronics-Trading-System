#include "../../include/system.h"

void System::mainMenu()
{
    bool isFinished = false;
    char option;
    cout << "Welcome to"
         << " " << this->getSystemName() << endl;
    printOpening();
    while (!isFinished)
    {
        bool isValid = true;
        if (this->logged_in_customer == nullptr && this->logged_in_seller == nullptr)
        { //Both are nullptr.
            printOptionsAsGuest();
            cin >> option;
            switch (option)
            {
            case '1':
                this->login();
                break;
            case '2':
                this->signup();
                break;
            case '3':
                this->printCustomersNames();
                break;
            case '4':
                this->printSellersNames();
                break;
            case '5':
                isFinished = true;
                break;
            default:
                cout << "Chosen option is not valid,try again." << endl;
                isValid = false;
                cin.ignore(256, '\n');
                break;
            }
        }
        else if (this->logged_in_customer != nullptr)
        {
            printOptionsAsCustomer();
            cin >> option;
            switch (option)

            {
            case '1':
                this->chooseProductToAddToCustomerWishlist();
                break;
            case '2':
                int x;
                this->printAllAvailableSellersToGiveFeedbacks(this->logged_in_customer);
                cout << "Please insert the number of the seller you want to leave a feedback on: ";
                cin >> x;

                this->logged_in_customer->addFeedBackToSeller(this->s_sellers_array[x - 1]);
                break;
            case '3':
                this->logged_in_customer->makeOrder();
                break;
            case '4':
                this->printSellersNames();
                break;
            case '5':
                cout << "Please insert the name of the product you want to search for: ";
                char name[11];
                cin.getline(name, 10);
                this->showProductsWithTheSameName(name);
                break;
            case '6':
                logged_in_customer = nullptr;
                break;
            case '7':
                isFinished = true;
                break;
            default:
                cout << "Chosen option is not valid,try again." << endl;
                isValid = false;
                break;
            }
        }
        else
        {
            printOptionsAsSeller();
            cin >> option;
            switch (option)
            {
            case '1':
                this->logged_in_seller->makeProductForSale();
                break;
            case '2':
                int size;
                FeedBack **array_feedbacks;
                array_feedbacks = this->logged_in_seller->getfeedBacksArray(size);
                if (size == 0)
                    cout << "there are no feedback availables please try again later" << endl;
                else
                {
                    cout << "your feedbacks are: " << endl;
                    for (int i = 0; i < size; i++)
                    {
                        array_feedbacks[i]->show();
                        cout << endl;
                    }
                }
                break;
            case '3':
                this->logged_in_seller = nullptr;
                break;
            case '4':
                isFinished = true;
                break;
            default:
                cout << "Chosen option is not valid,try again." << endl;
                isValid = false;
                break;
            }
        }
    }
}

bool System::checkUsernameAvailability(const char *username)
{
    for (int i = 0; i < this->customer_array_logical_size; i++)
    {
        if (strcmp(this->s_customers_array[i]->getName(), username) == 0)
            return false;
    }
    for (int i = 0; i < this->seller_array_logical_size; i++)
    {
        if (strcmp(this->s_sellers_array[i]->getUserName(), username) == 0)
            return false;
    }
    return true;
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
        bool isMatch = false;
        bool isExitedByWill = false;
        while (isFinishedSearch == false && i != this->customer_array_logical_size)
        {
            if (strcmp(s_customers_array[i]->getName(), username) == 0)
            {
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

                } while (isMatch == false && isExitedByWill == false);
            }
            else
                i++;
        }
        if (isFinishedSearch == false)
            cout << "Username did not found, returning to main menu." << endl;
    }
    else
    {
        cout << "There are no Customers Available" << endl;
    }
}
void System::sellerLogin()
{
    if (this->seller_array_logical_size != 0)
    {
        char username[11], password[11];
        cout << "Please enter your Username: ";
        cin.getline(username, 10);
        int i = 0;
        bool isFinishedSearch = false;
        while (isFinishedSearch == false && i != this->seller_array_logical_size)
        {
            if (strcmp(this->s_sellers_array[i]->getUserName(), username) == 0)
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

                } while (isMatch == false && isExitedByWill == false);
            }
            else
                i++;
        }
        if (isFinishedSearch == false)
            cout << "Username did not found, returning to main menu." << endl;
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