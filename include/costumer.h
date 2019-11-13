#ifndef __Costumer_H
#define __Costumer_H

#include "system.h"
#include "product.h"
#include "seller.h"

class Costumer
{
public:
	//constructors && distructors
	Costumer() = default;
	Costumer(const char *username, const char *password, const char *address, const Product **wishlist, int size = 0);
	Costumer(const Costumer &other);
	~Costumer();

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

#endif // !__Costumer_H
