#ifndef __USER_H
#define __USER_H

#include "address.h"
#include <fstream>
class Address;
class User
{
protected:
    char *m_username;
    char *m_password;
    Address m_address;
    User() = default;
    User(const char *name, const char *password, const Address &address);
    User(const User &other);
    User(User &&move);
    User(ifstream &in);
    /*Abstract Data Type*/
public:
    virtual ~User();
    virtual User *clone() const = 0;
    void setName(const char *name);
    void setPassword(const char *password);
    void setAddress(const Address address);
    virtual const User &operator=(const User &other);
    virtual const User &operator=(User &&other);
    virtual void toOs(ostream &out) const = 0;
    friend ostream &operator<<(ostream &out, const User &user);
    friend istream &operator>>(istream &out, User &user);

    const char *getName() const;
    const char *getPassword() const;
    //virtual void printOptions() const;

    const Address &getAddress() const;
};

#endif