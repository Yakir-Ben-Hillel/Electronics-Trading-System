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
	Customer(const char *username, const char *password,
			 Address *address, const Product **wishlist = nullptr,
			 unsigned int physicalSize = 0, unsigned int logicalSize = 0);
	Customer(const Customer &other);
	Customer(Customer &&other);
	~Customer();

	//seters
	bool setName(const char *userName);
	bool setAddress(Address *address);
	bool setPassword(const char *password);
	bool setWishList(const Product **wishList,int size);
	bool setOrder(Order *curr_order);		
	bool SetOrderArray(Order **order_array,int size); 
	bool addProductToWishlistArray(Product *new_product);

	//geters
	const char *getName() const;
	const Address *getAddress() const;
	const char *getPassWord() const;
	Product **getWishList() const;
	unsigned int getWishListPhysicalSize() const;
	unsigned int getWishListLogicalSize() const;
	unsigned int getLogicSizeOfOrder() const;
	unsigned int getPhySizeOfOrder() const;
	Order *getOrder(int location) const;
	Order **getOrderHistory() const;

	//other methoods
	void makeOrder();
	void showOrder(Order* curr);
	void deleteFromWishList(int location);
	void addFeedBackToSeller(const char* seller_name);
	

private:
	bool setWishListPhysicalSize(unsigned int physicalSize);
	bool setWishListLogicalSize(unsigned int logicallSize);
	void resizeWishlistArray();

	bool setOrderListPhySize(unsigned int PhySize);
	bool setOrderListLogicSize(unsigned int LogicSize);
	void resizeOrderlistArray();
	
	char *c_user_name;
	Address *c_address;
	char *c_password;			  //max length of password is 10 chars,can be letter or a number
	Product **c_wishList;		  //pointer array for product wish list
	int c_wish_physical_size = 1; 
	unsigned int c_wish_logical_size = 0;
	Order **orders_history; //array of all orders we have ever done,every part of the array contains a order we made.
	unsigned int order_physical_size = 1;
	unsigned int order_logical_size = 0;
};

#endif // !__Customer_H
