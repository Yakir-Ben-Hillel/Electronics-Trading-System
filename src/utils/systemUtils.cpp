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
                this->compareCustomers();
                break;
            case 7:
                isFinished = true;
                break;
            default:
                cout << "Chosen option is not valid,try again." << endl;
                isValid = false;
                cin.ignore(256, '\n');
                break;
            }
        }
        else if (customer_temp && !cas_temp)
        {
            printOptionsAsCustomer();
            cin >> option;
            bool check;
            switch (option)
            {
            case 1:
                this->chooseProductToAddToCustomerWishlist();
                break;
            case 2:
                do
                {
                    check = true;
                    try
                    {
                        this->addFeedback(customer_temp);
                    }
                    catch (const SystemException &e)
                    {
                        check = false;
                        e.show();
                    }
                } while (!check);
                break;
            case 3:
                do
                {
                    check = true;
                    try
                    {
                        customer_temp->makeOrder();
                    }
                    catch (const SystemException &e)
                    {
                        check = false;
                        e.show();
                    }
                } while (!check);
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
        else if (seller_temp && !cas_temp)
        {
            FeedBack **array_feedbacks = nullptr;
            printOptionsAsSeller();
            cin >> option;
            bool check;
            switch (option)
            {
            case 1:
                do
                {
                    check = true;
                    try
                    {
                        seller_temp->makeProductForSale();
                    }
                    catch (const SystemException &e)
                    {
                        check = false;
                        e.show();
                    }
                } while (!check);
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
            printOptionAsCAS();
            FeedBack **array_feedbacks = nullptr;
            cin >> option;
            bool check;
            switch (option)
            {
            case 1:
                this->chooseProductToAddToCustomerWishlist();
                break;
            case 2:
                do
                {
                    check = true;
                    try
                    {
                        this->addFeedback(customer_temp);
                    }
                    catch (const SystemException &e)
                    {
                        check = false;
                        e.show();
                    }

                } while (!check);
                break;
            case 3:
                do
                {
                    check = true;
                    try
                    {
                        customer_temp->makeOrder();
                    }
                    catch (const SystemException &e)
                    {
                        check = false;
                        e.show();
                    }

                } while (!check);

                break;
            case 4:
                this->printSellersNames();
                break;
                case 5:
                do
                {
                    check = true;
                    try
                    {
                        this->addFeedback(cas_temp);
                    }
                    catch (const SystemException &e)
                    {
                        check = false;
                        e.show();
                    }
                } while (!check);
                break;

            case 6:
                cout << "Please insert the name of the product you want to search for: ";
                char name[30];
                cin.ignore(256, '\n');
                cin.getline(name, 29);
                this->showProductsWithTheSameName(name);
                break;

            case 7:
                do
                {
                    check = true;
                    try
                    {
                        cas_temp->makeProductForSale();
                    }
                    catch (const SystemException &e)
                    {
                        check = false;
                        e.show();
                    }

                } while (!check);

                break;
            case 8:
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
            case 9:
                cout << *cas_temp;
                break;
            case 10:
                this->logged_in_user = nullptr;
                break;
            case 11:
                isFinished = true;
                break;
            }
        }
    }
    this->writeUsersToFile();
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