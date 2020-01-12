#include "../../include/system.h"

User::User(const string &name, const string &password, const Address &address) noexcept(false) : m_address(address)
{
    if (name.empty() || password.empty() || password.length > 10)
        throw UserException(name, password, address); //address has its own exception class, so if the address constractor will throw the function that called this user constractor will catch the throw
    setName(name);
    setPassword(password);
}
User::User(const User &other) : m_address(other.m_address), m_password(other.m_password), m_username(other.m_username)
{
}
User::User(User &&move) : m_address(std::move(move.m_address))
{
    *this = std::move(move);
}
User::User(ifstream &inFile)
{
    inFile >> *this;
}
void User::setName(const string &name)
{
    this->m_username = name;
}
void User::setPassword(const string &password)
{
    this->m_password = password;
}
void User::setAddress(const Address &address)
{
    this->m_address = address;
}
const User &User::operator=(const User &other)
{
    if (this != &other)
    {
        this->m_username = other.m_username;
        this->m_password = other.m_password;
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
const string &User::getName() const
{
    return this->m_username;
}
const string &User::getPassword() const
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
    if (this->m_username.compare(other.m_username))
        return true;
    return false;
}