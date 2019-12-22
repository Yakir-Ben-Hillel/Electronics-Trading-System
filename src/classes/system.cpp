#include "../../include/system.h"
System::System( User **users_array, User *logged_in_user,
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
            users_array[i] = new Customer(*given_users_array[i]);
        else if (typeid(given_users_array[i]) == typeid(Seller))
            users_array[i] = new Seller(*given_users_array[i]);
        else if (typeid(given_users_array[i]) == typeid(CAS))
            users_array[i] = new CAS(*given_users_array[i]);
        else
            return false; //Given users array is invalid.
    }
    return true;
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
