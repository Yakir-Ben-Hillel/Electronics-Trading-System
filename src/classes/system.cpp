#include "../../include/system.h"
System::System(vector<User *> users_array,
               User *logged_in_user) : users_array(move(users_array)),
                                       logged_in_user(logged_in_user)
{
}
System::System(const System &other) : users_array(move(other.users_array)), logged_in_user(other.logged_in_user)
{
}
System::~System()
{
    vector<User *>::iterator itr = this->users_array.begin();
    vector<User *>::iterator itrEnd = this->users_array.end();
    for (; itr != itrEnd; ++itr)
    {
        Customer *customerTemp = dynamic_cast<Customer *>(*itr);
        Seller *sellerTemp = dynamic_cast<Seller *>(*itr);
        CAS *casTemp = dynamic_cast<CAS *>(*itr);
        if (casTemp)
        {
            delete casTemp;
        }
        else if (sellerTemp)
        {
            delete sellerTemp;
        }
        else if (customerTemp)
        {
            delete customerTemp;
        }
    }
    this->users_array.clear();
}
bool System::setUsersArray(vector<User *> given_users_array)
{
    vector<User *>::iterator itr = given_users_array.begin();
    vector<User *>::iterator itrEnd = given_users_array.end();

    for (; itr != itrEnd; ++itr)
    {
        Customer *customerTemp = dynamic_cast<Customer *>(*itr);
        Seller *sellerTemp = dynamic_cast<Seller *>(*itr);
        CAS *casTemp = dynamic_cast<CAS *>(*itr);

        if (casTemp)
        {
            users_array.push_back(casTemp);
        }
        else if (sellerTemp)
        {
            users_array.push_back(sellerTemp);
        }
        else if (customerTemp)
        {
            users_array.push_back(customerTemp);
        }
        else
            return false; //Given users array is invalid.
    }
    return true;
}

const System &System::operator+=(User *user)
{
    Customer *temp_c = dynamic_cast<Customer *>(user);
    Seller *temp_s = dynamic_cast<Seller *>(user);
    CAS *temp_cas = dynamic_cast<CAS *>(user);
    if (temp_c && !temp_cas)
    {
        this->users_array.push_back(temp_c);
    }
    if (temp_s && !temp_cas)
    {
        this->users_array.push_back(temp_s);
    }
    if (temp_cas)
    {
        this->users_array.push_back(temp_cas);
    }
    return *this;
}
void System::loadUsersFromFile()
{
    ifstream inFile("Users.txt", ios::in);
    bool fEof = false;
    if (inFile)
    {
        string type;
        int amount;
        inFile >> amount;
        for (int i = 0; i < amount; i++)
        {
            inFile >> type;
            try
            {
                if (type.compare("Customer") == 0)
                {
                    *this += new Customer(inFile);
                }
                else if (type.compare("Seller") == 0)
                {
                    *this += new Seller(inFile);
                }
                else if (type.compare("CAS") == 0)
                {
                    *this += new CAS(inFile);
                }
                else
                {
                    std::cout << "INVALID INPUT INSIDE FILE!!! ABORTED." << endl;
                    exit(1);
                }
            }
            catch (SystemException &e)
            {
                e.show();//need to know first where the problem was,and repair the file!.
                cout << "FILE IS CURROPTED!!! ABORTED." << endl;
                exit(1);
            }
            if (inFile.eof())
            {
                fEof = true;
                continue;
            }
        }
    }
    inFile.close();
}
void System::writeUsersToFile()
{
    ofstream outFile("Users.txt", ios::trunc);
    outFile << this->users_array.size() << endl;
    vector<User *>::iterator itr = this->users_array.begin();
    vector<User *>::iterator itrEnd = this->users_array.end();

    for (; itr != itrEnd; ++itr)
    {
        outFile << *(*itr);
    }
    outFile.close();
}

void System::resizeUsersArray()
{
    this->users_array.reserve(this->users_array.size() * 2);
}
const string &System::getSystemName() const
{
    return system_name;
}
void System::compareCustomers() const
{
    int counter = 0;
    bool isValid = true;
    unsigned int temp_counter = 0;
    Customer *customerTemp = nullptr;
    vector<int> indexes_array;
    vector<User *>::const_iterator itr = this->users_array.begin();
    vector<User *>::const_iterator itrEnd = this->users_array.end();

    for (int i = 0; itr != itrEnd; ++itr, i++)
    {
        customerTemp = dynamic_cast<Customer *>(*itr);
        if (customerTemp)
        {
            indexes_array.push_back(i);
            temp_counter++;
            std::cout << temp_counter << ") " << customerTemp->getName() << endl;
        }
    }
    if (temp_counter > 1)
    {
        std::cout << endl;
        int op1, op2;
        do
        {
            std::cout << "Please choose the customers you would like to compare: (option1,option2) ";
            cin >> op1 >> op2;
            if ((op1 == op2) || (op1 < 0) || (op2 < 0) || (op1 > indexes_array.size()) || (op2 > indexes_array.size()))
            {
                std::cout << endl;
                std::cout << "wrong input,please try again!" << endl;
                isValid = false;
            }
            else
            {
                Customer *temp1, *temp2;
                itr = this->users_array.begin();
                vector<int>::iterator itrInt = indexes_array.begin();
                itrInt = itrInt + (op1 - 1);
                itr = itr + *itrInt;
                temp1 = dynamic_cast<Customer *>(*itr);
                itr = this->users_array.begin();
                itrInt = indexes_array.begin();
                itrInt = itrInt + (op2 - 1);
                itr = itr + *itrInt;
                temp2 = dynamic_cast<Customer *>(*itr);
                if (!temp1 || !temp2)
                {
                    std::cout << endl;
                    std::cout << "wrong input,please try again!" << endl;
                    isValid = false;
                }
                else
                {
                    isValid = true;
                    if (*temp1 < *temp2)
                    {
                        std::cout << temp2->getName() << "'s wishlist is bigger than " << temp1->getName() << "'s wishlist" << endl;
                    }
                    else if (*temp1 > *temp2)
                    {
                        std::cout << temp1->getName() << "'s wishlist is bigger than " << temp2->getName() << "'s wishlist" << endl;
                    }
                    else
                    {
                        std::cout << "The Customers Wishlists Prices are identical!" << endl;
                    }
                }
            }
        } while (!isValid);
    }
    else
        cout << "Not enough Customers Available." << endl;
}

void System::changePassWord()
{
    string temp;
    bool isSucceeded;
    do
    {
        isSucceeded = true;
        cout << "Please insert your current password: ";
        cin.ignore(1, '\n');
        getline(cin, temp);

        if (this->logged_in_user->getPassword() == temp)
        {
            cout << "Please insert your new password: ";
            getline(cin, temp);
            this->logged_in_user->setPassword(temp);
            cout << "Your password has changed!" << endl;
        }
        else
        {
            isSucceeded = false;
            cout << "the password you entered is incorrect, please try again!" << endl;
        }
    } while (!isSucceeded);
}
