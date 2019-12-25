#include "../../include/system.h"
System::System(User **users_array, User *logged_in_user,
               unsigned int users_array_physical_size,
               unsigned int users_array_logical_size) : users_array_physical_size(users_array_physical_size),
                                                        users_array_logical_size(users_array_logical_size),
                                                        logged_in_user(logged_in_user)
{
    setUsersArray(users_array);
}
System::System(const System &other) : users_array_physical_size(other.users_array_physical_size),
                                      users_array_logical_size(other.users_array_logical_size),
                                      logged_in_user(other.logged_in_user)
{
    setUsersArray(other.users_array);
}
System::~System()
{
    for (int i = 0; i < users_array_logical_size; i++)
        delete users_array[i];
    delete[] users_array;
    logged_in_user = nullptr;
}
bool System::setUsersArray(User **given_users_array)
{
    users_array = new User *[users_array_logical_size];
    for (int i = 0; i < users_array_logical_size; i++)
    {
        if (typeid(given_users_array[i]) == typeid(Customer))
        {
            Customer *customerTemp = dynamic_cast<Customer *>(given_users_array[i]);
            users_array[i] = new Customer(*customerTemp);
        }
        else if (typeid(given_users_array[i]) == typeid(Seller))
        {
            Seller *sellerTemp = dynamic_cast<Seller *>(given_users_array[i]);
            users_array[i] = new Seller(*sellerTemp);
        }
        else if (typeid(given_users_array[i]) == typeid(CAS))
        {
            CAS *casTemp = dynamic_cast<CAS *>(given_users_array[i]);
            users_array[i] = new CAS(*casTemp);
        }
        else
            return false; //Given users array is invalid.
    }
    return true;
}

const System &System::operator+=(User *user)
{
    if (this->users_array_logical_size == this->users_array_physical_size)
        this->resizeUsersArray();
    Customer *temp_c = dynamic_cast<Customer *>(user);
    Seller *temp_s = dynamic_cast<Seller *>(user);
    CAS *temp_cas = dynamic_cast<CAS *>(user);
    if (temp_c && !temp_cas)
    {
        this->users_array[this->users_array_logical_size] = temp_c;
        this->users_array_logical_size++;
    }
    if (temp_s && !temp_cas)
    {
        this->users_array[this->users_array_logical_size] = temp_s;
        this->users_array_logical_size++;
    }
    if (temp_cas)
    {
        this->users_array[this->users_array_logical_size] = temp_cas;
        this->users_array_logical_size++;
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
    outFile << this->users_array_logical_size << endl;
    for (int i = 0; i < this->users_array_logical_size; i++)
    {
        outFile << *this->users_array[i];
    }
    outFile.close();
}

void System::resizeUsersArray()
{
    int newSize = this->users_array_physical_size * 2 + 1;
    User **newArray = new User *[newSize];
    memcpy(newArray, this->users_array, this->users_array_logical_size * sizeof(User *));
    delete[] this->users_array;
    this->users_array_physical_size = newSize;
    this->users_array = newArray;
}
const char *System::getSystemName() const
{
    return system_name;
}
void System::compare() const
{
    int counter = 0;
    bool isValid = true;
    unsigned int temp_counter = 0;
    Customer *customerTemp = nullptr;
    for (int i = 0; i < this->users_array_logical_size; i++)
    {
        customerTemp = dynamic_cast<Customer *>(this->users_array[i]);
        if (customerTemp)
        {
            std::cout << i + 1 << ") " << customerTemp << endl;
            temp_counter++;
        }
    }
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
        temp1 = dynamic_cast<Customer *>(this->users_array[op1]);
        temp2 = dynamic_cast<Customer *>(this->users_array[op2]);
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
            else
            {
                std::cout << temp1->getName() << "'s wishlist is bigger than " << temp2->getName() << "'s wishlist" << endl;
            }
        }

    } while (!isValid);
}
