#ifndef __Customer_H
#define __Customer_H
//#include "seller.h"
#include "system.h"

class Customer : virtual public User
{
public:
	//constructors && distructors
	Customer(const string &username, const string &password, const Address &address,
			 const vector<Product *> wishlist,
			 const vector<Order *> orderHistory) noexcept(false);
	Customer(const Customer &other);
	Customer(ifstream &inFile);
	Customer(Customer &&other);
	virtual ~Customer();
	//operator=
	const Customer &operator=(const Customer &other);
	friend bool operator<(const Customer &first, const Customer &second);
	friend bool operator>(const Customer &first, const Customer &second);
	virtual bool operator==(const User &other) const;
	virtual User *clone() const override;
	// friend istream &operator>>(istream &in, Customer &customer);
	//seters
	bool setWishList(const vector<Product *> wishList);
	bool setOrder(const Order *curr_order);
	bool SetOrderArray(const vector<Order *> order_array);
	bool addProductToWishlistArray(Product *new_product);
	virtual void toOs(ostream &out) const override;
	//geters
	vector<Product *> getWishList() const;
	unsigned int getWishListPhysicalSize() const;
	unsigned int getWishListLogicalSize() const;
	unsigned int getLogicSizeOfOrder() const;
	unsigned int getPhySizeOfOrder() const;
	const Order &getOrder(int location) const;
	vector<Order *> getOrderHistory() const;

	//other methoods
	void makeOrder() noexcept(false);
	void deleteFromWishList(int location);
	void addFeedBackToSeller(Seller *seller) noexcept(false);
	bool didCustomerOrderedFromSeller(Seller *seller);

protected:
	vector<Product *> c_wishList;   //pointer array for product wish list
	vector<Order *> orders_history; //array of all orders we have ever done,every part of the array contains a order we made.
	Customer() = default;
	void resizeWishlistArray();
	void resizeOrderlistArray();
	void getSum(float &sum) const;
};

#endif // !__Customer_H
