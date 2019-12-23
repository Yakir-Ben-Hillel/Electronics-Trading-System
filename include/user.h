#ifndef __USER_H
#define __USER_H

#include "address.h"
class Address;
class User
{
protected:
    char *m_username;
    char *m_password;
    Address m_address;
    User(char *name, char *password, Address &address);
    User(const User &other);
    User(User &&move);
    /*Abstract Data Type*/
public:
    virtual ~User() = 0;
    void setName(char *name);
    void setPassword(char *password);
    void setAddress(Address address);
    virtual const User &operator=(const User &other);
    virtual const User &operator=(User &&other);
    virtual void toOs(ostream& out) const=0;
    friend ostream& operator<<(ostream& out,const User& user);
    const char *getName() const;
    const char *getPassword() const;
    //virtual void printOptions() const;

    const Address &getAddress() const;
};

#endif