#include "../../include/user.h"

User::User(char *name, char *password, Address address) : m_address(address)
{
    setName(name);
    setPassword(password);
}
User::User(const User &other) : m_address(other.m_address),m_username(NULL),m_password(NULL)
{
    *this=other;
}
User::User(User &&move) : m_address(std::move(move.m_address))
{
    *this=std::move(move);
}
User::~User()
{
    delete[] m_username;
    delete[] m_password;
}
void User::setName(char *name)
{
    this->m_username=strdup(name);
}
void User::setPassword(char *password)
{
    this->m_password=strdup(password);
}
void User::setAddress(Address address)
{
    this->m_address=address;//to do operator= for address
}
const User &User::operator=(const User &other)
{
    if(this!=&other)
    {
        delete[] m_username;
        m_username=strdup(other.m_username);

        delete m_password;
        m_password=strdup(other.m_password);

        m_address=other.m_address;//to do operator= for address
    }
    return *this;
}
const User &User::operator=(User &&other)
{
    std::swap(m_username,other.m_username);
    std::swap(m_password,other.m_password);
    m_address=std::move(other.m_address);//to do move operator=

    return *this;
}
char *User::getName() const
{
    return this->m_username;
}
char *User::getPassword() const
{
    return this->m_password;
}
const Address &User::getAddress() const
{
    return this->m_address;
}