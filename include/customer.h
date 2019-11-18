#ifndef __Customer_H
#define __Customer_H

class Address;
class Product;
class Order;

class Customer
{
public:
	//constructors && distructors
	Customer() = default;
	Customer(const char *username, const char *password, const Address *address, const Product **wishlist, int size = 0);
	Customer(const Customer &other);
	Customer(Customer &&other);
	~Customer();

	//seters
	bool setName(const char *userName);
	bool setAddress(const Address *address);
	bool setPassword(const char *password);
	bool setWishList(const Product **wishList);
	bool setSizeWishList(int size);
	bool setOrder(Order* curr_order);//
	bool SetOrderArray(Order** order_array);//
	

	//geters
	const char *getName() const;
	const Address *getAddress() const;
	const char *getPassWord() const;
	const Product **getWishList() const;
	int getSizeWishList() const;
	int getSizeOfOrder() const;			 //
	Order *getOrder(int location) const; //
	Order **getOrderHistory() const;	 //
	//other methoods

private:
	char *c_user_name;
	Address *c_address;
	char *c_password;		//max length of password is 10 chars,can be letter or a number
	Product **c_wishList;   //pointer array for product wish list
	int c_wish_size = 0;	//by default the size of the wish list is 0
	Order **orders_history; //array of all orders we have ever done,every part of the array contains a order we made.
	int order_size = 0;
};

#endif // !__Customer_H
