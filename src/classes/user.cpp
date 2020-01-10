#include "../../include/system.h"

User::User(const char *name, const char *password, const Address &address) noexcept(false) : m_address(address)
{
    if (strcmp(name, "") == 0 || strcmp(password, "") == 0 || strlen(password) > 10)
        throw UserException(name, password, address); //address has its own exception class, so if the address constractor will throw the function that called this user constractor will catch the throw
    setName(name);
    setPassword(password);
}
User::User(const User &other) : m_address(other.m_address),m_password(nullptr),m_username(nullptr)
{
    *this = other;
}
User::User(User &&move) : m_address(std::move(move.m_address))
{
    *this = std::move(move);
}
User::User(ifstream &inFile)
{
    inFile >> *this;
}
User::~User()
{
    delete[] m_username;
    delete[] m_password;
}
void User::setName(const char *name)
{
    if (this->m_username)
        delete[] this->m_username;
    this->m_username = strdup(name);
}
void User::setPassword(const char *password)
{
    if (this->m_password)
        delete[] this->m_password;
    this->m_password = strdup(password);
}
void User::setAddress(const Address &address)
{
    this->m_address = address;
}
const User &User::operator=(const User &other)
{
    if (this != &other)
    {
        delete[] m_username;
        m_username = strdup(other.m_username);

        delete[] m_password;
        m_password = strdup(other.m_password);
        m_address = other.m_address; //to do operator= for address
    }
    return *this;
}
const User &User::operator=(User &&other)
{
    std::swap(m_username, other.m_username);
    std::swap(m_password, other.m_password);
    m_address = std::move(other.m_address); //to do move operator=

    return *this;
}
const char *User::getName() const
{
    return this->m_username;
}
const char *User::getPassword() const
{
    return this->m_password;
}
const Address &User::getAddress() const
{
    return this->m_address;
}

ostream &operator<<(ostream &out, const User &user)
{
    if (typeid(out) == typeid(ofstream))
    { //No +6 is needed when using Glibc.
        out << typeid(user).name() + 1 << " " << user.m_username << " " << user.m_password << " " << user.m_address;
    }
    else
    {
        out << "Username: " << user.m_username << endl;
        out << user.m_address;
        user.toOs(out);
    }
    return out;
}
istream &operator>>(istream &in, User &user)
{
    char username[11], password[11];
    in >> username;
    in >> password;
    user.setName(username);
    user.setPassword(password);
    in >> user.m_address;
    return in;
}

bool User::operator==(const User &other) const
{
    if (strcmp(m_username, other.m_username) == 0)
        return true;
    return false;
}