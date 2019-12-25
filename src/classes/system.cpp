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
    this->users_array[this->users_array_logical_size] = user;
    this->users_array_logical_size++;
    return *this;
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
//not done yet
void System::compare() const
{
    int counter = 0;
    bool isValid=true;
    this->printCustomersNames(&counter);
    int op1, op2;
    do
    {
        cout << "Please choose the customers you would like to compare: (option1 option2) ";
        cin >> op1 >> op2;
        if((op1==op2)||(op1>counter)||(op2>counter)||(op1<0)||(op2<0))
        {
            cout<<endl<<"wrong input,please try again!"<<endl;
            isValid=false;
        }
    } while (!isValid);
}
