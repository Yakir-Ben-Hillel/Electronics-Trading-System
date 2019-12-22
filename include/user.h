#ifndef __USER_H
#define __USER_H

#include "address.h"
#include "system.h"

class User 
{
protected:
char* m_username;
char* m_password;
Address m_address;

public:
User(char* name,char* password,Address &address);
User(const User& other);
User(User&& move);
~User();
void setName(char* name);
void setPassword(char* password);
void setAddress(Address address);
const User& operator=(const User& other);
const User& operator=(User&& other);
const char* getName() const;
const char* getPassword() const;
const Address& getAddress() const;
};

#endif