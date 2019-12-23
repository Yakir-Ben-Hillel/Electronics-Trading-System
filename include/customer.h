#ifndef __Customer_H
#define __Customer_H
#include "seller.h"
#include "user.h"
class Address;
class Product;
class Order;

class Customer : virtual public User
{
public:
	//constructors && distructors
	Customer() = default;
	Customer(const User &user,
			 const Product **wishlist = nullptr,
			 const Order **orderHistory = nullptr,
			 unsigned int orderHistoryPhysicalSize = 0,
			 unsigned int orderHistoryLogicalSize = 0,
			 unsigned int wishlistPhysicalSize = 0,
			 unsigned int wishlistLogicalSize = 0);

	Customer(char *username, char *password, Address &address,
			 const Product **wishlist = nullptr,
			 const Order **orderHistory = nullptr,
			 unsigned int orderHistoryPhysicalSize = 0,
			 unsigned int orderHistoryLogicalSize = 0,
			 unsigned int wishlistPhysicalSize = 0,
			 unsigned int wishlistLogicalSize = 0);
	Customer(const Customer &other);
	Customer(Customer &&other);
	virtual ~Customer();
	//operator=
	const Customer &operator=(const Customer &other);
	//seters
	bool setName(char *userName);
	bool setAddress(Address address);
	bool setPassword(char *password);
	bool setWishList(const Product **wishList, int size);
	bool setOrder(const Order *curr_order);
	bool SetOrderArray(const Order **order_array, int size);
	bool addProductToWishlistArray(Product *new_product);

	//geters
	const char *getName() const;
	const Address &getAddress() const;
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
	void showOrder(Order *curr);
	void deleteFromWishList(int location);
	void addFeedBackToSeller(Seller *seller);
	bool didCustomerOrderedFromSeller(Seller *seller);

protected:
	bool setWishListPhysicalSize(unsigned int physicalSize);
	bool setWishListLogicalSize(unsigned int logicallSize);
	void resizeWishlistArray();

	bool setOrderListPhySize(unsigned int PhySize);
	bool setOrderListLogicSize(unsigned int LogicSize);
	void resizeOrderlistArray();

	Product **c_wishList; //pointer array for product wish list
	int c_wish_physical_size = 1;
	unsigned int c_wish_logical_size = 0;
	Order **orders_history; //array of all orders we have ever done,every part of the array contains a order we made.
	unsigned int order_physical_size = 1;
	unsigned int order_logical_size = 0;
};

#endif // !__Customer_H
