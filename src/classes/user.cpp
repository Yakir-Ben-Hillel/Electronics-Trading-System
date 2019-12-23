#include "../../include/system.h"

User::User(const char *name, const char *password, const Address &address) : m_address(address)
{
    setName(name);
    setPassword(password);
}
User::User(const User &other) : m_address(other.m_address)
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
    this->m_username = strdup(name);
}
void User::setPassword(const char *password)
{
    this->m_password = strdup(password);
}
void User::setAddress(const Address address)
{
    this->m_address = address; //to do operator= for address
}
const User &User::operator=(const User &other)
{
    if (this != &other)
    {
        delete[] m_username;
        m_username = strdup(other.m_username);

        delete m_password;
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
        out << typeid(user).name() << " " << user.m_username << " " << user.m_password << " " << user.m_address;
    }
    else
    {
        out << user.m_username << " " << user.m_address;
    }
    user.toOs(out);
    return out;
}
istream &operator>>(istream &in, User &user)
{
    char username[11], password[11];
    Address address;
    in >> username >> password >> address;
    user.setName(username);
    user.setPassword(password);
    user.setAddress(address);
    return in;
}