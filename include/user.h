#ifndef __USER_H
#define __USER_H
#include "address.h"
class Product;
class FeedBack;
class User
{
protected:
    string m_username;
    string m_password;
    Address m_address;
    User() = default;
    User(const string &name, const string &password, const Address &address) noexcept(false);
    User(const User &other);
    User(User &&move);
    User(ifstream &inFile);
    //protected methoods
    void setName(const string &name); //the user cannot change its name but he can change password or change the address

public:
    virtual ~User() {}
    virtual User *clone() const = 0; /*Abstract Data Type*/
    void setPassword(const string &password);
    void setAddress(const Address &address);
    virtual const User &operator=(const User &other);
    virtual const User &operator=(User &&other);
    virtual void toOs(ostream &out) const = 0;
    friend ostream &operator<<(ostream &out, const User &user);
    friend istream &operator>>(istream &out, User &user);
    virtual bool operator==(const User &other) const;

    const string &getName() const;
    const string &getPassword() const;
    const Address &getAddress() const;
};
#endif