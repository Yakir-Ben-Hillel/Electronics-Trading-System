#include "../../include/system.h"
System::System(vector<User *> users_array,
               User *logged_in_user) : users_array(move(users_array)),
                                       logged_in_user(logged_in_user)
{
}
System::System(const System &other) : users_array(move(other.users_array)), logged_in_user(other.logged_in_user)
{
}
bool System::setUsersArray(vector<User *> given_users_array)
{
    vector<User *>::iterator itr = given_users_array.begin();
    vector<User *>::iterator itrEnd = given_users_array.end();

    for (; itr != itrEnd; ++itr)
    {
        if (typeid(*itr) == typeid(Customer))
        {
            Customer *customerTemp = dynamic_cast<Customer *>(*itr);
            users_array.push_back(customerTemp);
        }
        else if (typeid(*itr) == typeid(Seller))
        {
            Seller *sellerTemp = dynamic_cast<Seller *>(*itr);
            users_array.push_back(sellerTemp);
        }
        else if (typeid(*itr) == typeid(CAS))
        {
            CAS *casTemp = dynamic_cast<CAS *>(*itr);
            users_array.push_back(*itr);
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
        char type[10];
        int amount;
        inFile >> amount;
        for (int i = 0; i < amount; i++)
        {
            inFile >> type;
            try
            {
                if (strcmp(type, "Customer") == 0)
                {
                    *this += new Customer(inFile);
                }
                else if (strcmp(type, "Seller") == 0)
                {
                    *this += new Seller(inFile);
                }
                else if (strcmp(type, "CAS") == 0)
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
    for (int i = 0; this->users_array.size(); i++)
    {
        outFile << *this->users_array[i];
    }
    outFile.close();
}

void System::resizeUsersArray()
{
    this->users_array.reserve(this->users_array.size() * 5);
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
    int *indexes_array = new int[this->users_array.size()];

    for (int i = 0; i < this->users_array.size(); i++)
    {
        customerTemp = dynamic_cast<Customer *>(this->users_array[i]);
        if (customerTemp)
        {
            indexes_array[temp_counter] = i;
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
            std::cout << "Please choose the customers you would like to compare: (option1 option2) ";
            cin >> op1 >> op2;
            if ((op1 == op2) || (op1 < 0) || (op2 < 0))
            {
                std::cout << endl;
                std::cout << "wrong input,please try again!" << endl;
                isValid = false;
            }
            Customer *temp1, *temp2;
            temp1 = dynamic_cast<Customer *>(this->users_array[indexes_array[op1 - 1]]);
            temp2 = dynamic_cast<Customer *>(this->users_array[indexes_array[op2 - 1]]);
            if (!temp1 || !temp2)
            {
                std::cout << endl;
                std::cout << "wrong input,please try again!" << endl;
                isValid = false;
            }
            else
            {
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

        } while (!isValid);
    }
    else
        cout << "Not enough Customers Available." << endl;
    delete[] indexes_array;
}

void System::changePassWord()
{
    char temp[256];
    bool isSucceeded ;
    do
    {
        isSucceeded = true;
        cout << "Please insert your current password: ";
        cin.ignore(1,'\n');
        cin.getline(temp, 256, '\n');

        if (this->logged_in_user->getPassword() == temp)
        {
            this->logged_in_user->setPassword(string(temp));
            cout << endl;
            cout << "your password has changed!" << endl;
        }
        isSucceeded = false;
        cout <<"the password you entered is incorrect, please try again!"<<endl;
    } while (isSucceeded);

    return;
}