#ifndef __Customer_H
#define __Customer_H

#include "system.h"
#include "product.h"
#include "seller.h"

class Customer
{
public:
	/*struct Address
	{
		char city[12];
		char street[12];
		unsigned short int num_of_street;
	}an option to define the address by struct or use another class?*/
	//constructors && distructors
	Customer() = default;
	Customer(const char *username, const char *password, const char *address, const Product **wishlist, int size = 0);
	Customer(const Customer &other);
	~Customer();

	//seters
	bool setName(const char *userName);
	bool setAddress(const char *address);
	bool setPassword(const char *password);
	bool setWishList(const Product **wishList);
	bool setSize(int size);

	//geters
	const char *getName() const;
	const char *getAddress() const;
	const char *getPassWord() const;
	const Product **getWishList() const;
	int getSize() const;

	//other methoods

private:
	char *c_user_name;
	char *c_address;
	char c_password[11];  //max length of password is 10 chars,can be letter or a number
	Product **c_wishList; //pointer array for product wish list
	int c_wish_size = 0;  //bu default the size of the wish list is 0
};

#endif // !__Customer_H
