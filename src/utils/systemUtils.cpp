#include "../../include/system.h"

void System::mainMenu()
{
    this->loadUsersFromFile();
    bool isFinished = false;
    int option;
    cout << "Welcome to"
         << " " << this->getSystemName() << endl;
    printOpening();
    Customer *customer_temp = nullptr;
    Seller *seller_temp = nullptr;
    CAS *cas_temp = nullptr;
    while (!isFinished)
    {
        customer_temp = dynamic_cast<Customer *>(this->logged_in_user);
        seller_temp = dynamic_cast<Seller *>(this->logged_in_user);
        cas_temp = dynamic_cast<CAS *>(this->logged_in_user);
        bool isValid = true;
        if (!this->logged_in_user)
        {
            printOptionsAsGuest();
            cin >> option;
            cin.ignore(256, '\n');
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
                this->printCASNames();
                break;
            case 6:
                isFinished = true;
                break;
            default:
                cout << "Chosen option is not valid,try again." << endl;
                isValid = false;
                cin.ignore(256, '\n');
                break;
            }
        }
        else if (customer_temp)
        {
            printOptionsAsCustomer();
            cin >> option;
            switch (option)
            {
            case 1:
                this->chooseProductToAddToCustomerWishlist();
                break;
            case 2:
                this->addFeedback(customer_temp);
                break;
            case 3:
                customer_temp->makeOrder();
                break;
            case 4:
                this->printSellersNames();
                break;
            case 5:
                cout << "Please insert the name of the product you want to search for: ";
                char name[30];
                cin.getline(name, 29);
                this->showProductsWithTheSameName(name);
                break;
            case 6:
                cout << *customer_temp;
                break;
            case 7:
                this->logged_in_user = nullptr;
                break;
            case 8:
                isFinished = true;
                break;
            default:
                cout << "Chosen option is not valid,try again." << endl;
                isValid = false;
                break;
            }
        }
        else if (seller_temp)
        {
            FeedBack **array_feedbacks = nullptr;
            printOptionsAsSeller();
            cin >> option;
            switch (option)
            {
            case 1:
                seller_temp->makeProductForSale();
                break;
            case 2:
                int size;
                array_feedbacks = seller_temp->getfeedBacksArray(size);
                if (size == 0)
                    cout << "there are no feedback availables please try again later" << endl;
                else
                {
                    cout << "your feedbacks are: " << endl;
                    for (int i = 0; i < size; i++)
                    {
                        cout << (*array_feedbacks)[i];
                        cout << endl;
                    }
                }
                break;
            case 3:
                cout << *seller_temp;
                break;

            case 4:
                this->logged_in_user = nullptr;
                break;
            case 5:
                isFinished = true;
                break;
            default:
                cout << "Chosen option is not valid,try again." << endl;
                isValid = false;
                break;
            }
        }
        else if (cas_temp)
        {
            FeedBack **array_feedbacks = nullptr;
            cin >> option;
            switch (option)
            {
            case 1:
                this->chooseProductToAddToCustomerWishlist();
                break;
            case 2:
                this->addFeedback(customer_temp);
                break;
            case 3:
                customer_temp->makeOrder();
                break;
            case 4:
                this->printSellersNames();
                break;
            case 5:
                cout << "Please insert the name of the product you want to search for: ";
                char name[30];
                cin.getline(name, 29);
                this->showProductsWithTheSameName(name);
                break;

            case 6:
                cas_temp->makeProductForSale();
                break;
            case 7:
                int size;
                array_feedbacks = cas_temp->getfeedBacksArray(size);
                if (size == 0)
                    cout << "there are no feedback availables please try again later" << endl;
                else
                {
                    cout << "your feedbacks are: " << endl;
                    for (int i = 0; i < size; i++)
                    {
                        cout << (*array_feedbacks)[i];
                        cout << endl;
                    }
                }
                break;
            case 8:
                this->logged_in_user = nullptr;
                break;
            case 9:
                isFinished = true;
                break;
            }
        }
    }
    this->writeUsersToFile();
}
bool System::addFeedback(Customer *customer)
{
    int *indexes_array = new int[users_array_logical_size];
    int x;
    Seller *seller_temp = nullptr;
    int available_index_counter = 0;
    for (int i = 0; i < users_array_logical_size; i++)
    {
        seller_temp = dynamic_cast<Seller *>(this->users_array[i]);
        if (seller_temp)
            if (customer->didCustomerOrderedFromSeller(seller_temp))
                indexes_array[available_index_counter] = i;
    }
    if (available_index_counter != 0)
    {
        this->printAllAvailableSellersToGiveFeedbacks(customer);
        cout << "Please insert the number of the seller you want to leave a feedback on: ";
        cin >> x;
        x--;
        seller_temp = dynamic_cast<Seller *>(this->users_array[indexes_array[x]]);
        if (seller_temp)
        {
            customer->addFeedBackToSeller(seller_temp);
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
    delete[] indexes_array;
}
bool System::checkUsernameAvailability(const char *username)
{
    for (int i = 0; i < this->users_array_logical_size; i++)
    {
        if (strcmp(this->users_array[i]->getName(), username) == 0)
            return false;
    }
    return true;
}
void System::signup()
{
    User *user = nullptr;
    Address *address = nullptr;
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
    switch (chosen_type)
    {
    case 1:
        user = new Customer(username, password, *address);
        break;
    case 2:
        user = new Seller(username, password, *address);
        break;
    case 3:
        user = new CAS(username, password, *address);
        break;
    default:
        break;
    }
    *this += user;
}
void System::login()
{
    if (this->users_array_logical_size)
    {
        char username[11], password[11];
        cout << "Please enter your Username" << endl;
        cin.getline(username, 10);
        int i = 0;
        bool isFinishedSearch = false;
        bool isMatch = false;
        bool isExitedByWill = false;
        while (isFinishedSearch == false && i != this->users_array_logical_size)
        {
            if (strcmp(users_array[i]->getName(), username) == 0)
            {
                isFinishedSearch = true;
                do
                {
                    cout << "Please insert your Password, write 'back' in any given time to go main menu." << endl;
                    cin.getline(password, 10);
                    if (strcmp(password, "back") == 0)
                        isExitedByWill = true;
                    else if (strcmp(password, users_array[i]->getPassword()) == 0)
                    {
                        this->logged_in_user = users_array[i];
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
        cout << "There are no Users Available" << endl;
    }
}
void System::showProductsWithTheSameName(const char *name)
{
    Seller *seller_temp = nullptr;
    CAS *cas_temp = nullptr;
    cout << "The Products you have searched for ,show to you below: " << endl;
    for (int i = 0; i < this->users_array_logical_size; i++)
    {
        seller_temp = dynamic_cast<Seller *>(users_array[i]);
        cas_temp = dynamic_cast<CAS *>(users_array[i]);
        if (seller_temp)
        {
            int size = seller_temp->getStockArraySize();
            Product **stock = seller_temp->getStock();
            for (int j = 0; j < size; j++)
            {
                if (isSubstring(name, stock[j]->getName()))
                {
                    cout << *stock[j];
                    cout << endl;
                }
            }
        }
        if (cas_temp)
        {
            int size = cas_temp->getStockArraySize();
            Product **stock = cas_temp->getStock();
            for (int j = 0; j < size; ++j)
            {
                if (isSubstring(name, stock[j]->getName()))
                {
                    cout << *stock[j];
                    cout << endl;
                }
            }
        }
    }
}
bool isSubstring(const char *s1, const char *s2)
{
    int M = strlen(s1);
    int N = strlen(s2);
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
        if (j == M)
            return true;
    }
    return false;
}