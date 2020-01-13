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
            string name;
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
                        this->addFeedback(*customer_temp);
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
                getline(cin, name);
                this->showProductsWithTheSameName(name);
                break;
            case 6:
                cout << *customer_temp;
                break;
            case 7:
                this->changePassWord();
                break;
            case 8:
                this->logged_in_user = nullptr;
                break;
            case 9:
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
            printOptionsAsSeller();
            cin >> option;
            bool check;
            vector<FeedBack*> array_feedbacks;
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
                array_feedbacks = seller_temp->getfeedBacksArray();
                if (array_feedbacks.empty())
                    cout << "there are no feedback availables please try again later" << endl;
                else
                {
                    vector<FeedBack*>::iterator fItr = array_feedbacks.begin();
                    vector<FeedBack*>::iterator fItrEnd = array_feedbacks.end();
                    cout << "your feedbacks are: " << endl;
                    for (; fItr != fItrEnd; ++fItr)
                    {
                        cout << *(*fItr);
                        cout << endl;
                    }
                }
                break;
            case 3:
                cout << *seller_temp;
                break;
            case 4:
                this->changePassWord();
                break;
            case 5:
                this->logged_in_user = nullptr;
                break;
            case 6:
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
            vector<FeedBack*> array_feedbacks;
            string name;
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
                        this->addFeedback(*customer_temp);
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
                        this->addFeedback(*cas_temp);
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
                cin.ignore(256, '\n');
                getline(cin, name);
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
                array_feedbacks = cas_temp->getfeedBacksArray();
                if (array_feedbacks.empty())
                    cout << "there are no feedback availables please try again later" << endl;
                else
                {
                    vector<FeedBack*>::iterator fItr = array_feedbacks.begin();
                    vector<FeedBack*>::iterator fItrEnd = array_feedbacks.end();
                    cout << "your feedbacks are: " << endl;
                    for (; fItr != fItrEnd; ++fItr)
                    {
                        cout << *(*fItr);
                        cout << endl;
                    }
                }
                break;
            case 9:
                cout << *cas_temp;
                break;
            case 10:
                this->changePassWord();
                break;
            case 11:
                this->logged_in_user = nullptr;
                break;
            case 12:
                isFinished = true;
                break;
            }
        }
    }
    this->writeUsersToFile();
}
bool System::checkUsernameAvailability(const string &username)
{
    vector<User *>::const_iterator itr = this->users_array.begin();
    vector<User *>::const_iterator itrEnd = this->users_array.end();
    for (; itr != itrEnd; ++itr)
    {
        if ((*itr)->getName().compare(username) == 0)
            return false;
    }
    return true;
}
void System::login()
{

    if (!this->users_array.empty())
    {
        string username, password;
        cout << "Please enter your Username" << endl;
        getline(cin, username);
        vector<User *>::const_iterator itr = this->users_array.begin();
        vector<User *>::const_iterator itrEnd = this->users_array.end();
        bool isFinishedSearch = false;
        bool isMatch = false;
        bool isExitedByWill = false;
        while (isFinishedSearch == false && itr != itrEnd)
        {
            if ((*itr)->getName().compare(username) == 0)
            {
                isFinishedSearch = true;
                do
                {
                    cout << "Please insert your Password, write 'back' in any given time to go main menu." << endl;
                    getline(cin, password);
                    if (password.compare("back") == 0)
                        isExitedByWill = true;
                    else if (password.compare((*itr)->getPassword()) == 0)
                    {
                        this->logged_in_user = *itr;
                        isMatch = true;
                    }
                    else
                    {
                        cout << "Password incorrect please try again." << endl;
                    }

                } while (isMatch == false && isExitedByWill == false);
            }
            else
                ++itr;
        }
        if (isFinishedSearch == false)
            cout << "Username did not found, returning to main menu." << endl;
    }
    else
    {
        cout << "There are no Users Available" << endl;
    }
}
bool isSubstring(const string &s1, const string &s2)
{
    int M = s1.size();
    int N = s2.size();
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