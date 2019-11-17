#ifndef __Customer_H
#define __Customer_H

#include "system.h"

class Address;
class Product;

class Customer
{
public:
	//constructors && distructors
	Customer() = default;
	Customer(const char *username, const char *password, const Address *address, const Product **wishlist, int size = 0,int price=0);
	Customer(const Customer &other);
	~Customer();

	//seters
	bool setName(const char *userName);
	bool setAddress(const Address *address);
	bool setPassword(const char *password);
	bool setWishList(const Product **wishList);
	bool setSize(int size);
	bool setTotalPrice(int price);

	//geters
	const char *getName() const;
	const Address *getAddress() const;
	const char *getPassWord() const;
	const Product **getWishList() const;
	int getSize() const;
	int getTotalPrice() const;

	//other methoods

private:
	char *c_user_name;
	Address *c_address;
	char c_password[11];  //max length of password is 10 chars,can be letter or a number
	Product **c_wishList; //pointer array for product wish list
	int c_wish_size = 0;  //by default the size of the wish list is 0
	int c_total_price=0;//the total price of the order the customer would like to do.
};

#endif // !__Customer_H
