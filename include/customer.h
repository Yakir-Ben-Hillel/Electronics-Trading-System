#ifndef __Customer_H
#define __Customer_H
//#include "seller.h"
#include "user.h"
class Seller;
class Order;
class Customer : virtual public User
{
public:
	//constructors && distructors
	Customer(const Customer &other);
	Customer(ifstream &inFile);
	Customer(Customer &&other);
	Customer(const string &username, const string &password, const Address &address,
			 const vector<Product> &wishlist = vector<Product>(),const vector<Order> &orderHistory = vector<Order>()) noexcept(false);
	virtual ~Customer();
	const Customer &operator=(const Customer &other);
	friend bool operator<(const Customer &first, const Customer &second);
	friend bool operator>(const Customer &first, const Customer &second);
	virtual bool operator==(const User &other) const;
	virtual User *clone() const override;
	// friend istream &operator>>(istream &in, Customer &customer);
	//seters
	void setWishList(const vector<Product> &wishList);
	bool AddOrderToArray(const Order &given_order);
	void SetOrderArray(const vector<Order> &order_array);
	bool addProductToWishlistArray(const Product &new_product);
	virtual void toOs(ostream &out) const override;
	//geters
	vector<Product> getWishList() const;
	const Order &getOrder(int location) const;
	vector<Order> getOrderHistory() const;

	//other methoods
	void makeOrder() noexcept(false);
	void addFeedBackToSeller(Seller &seller) noexcept(false);
	bool didCustomerOrderedFromSeller(Seller &seller);

protected:
	vector<Product> c_wishList;   //pointer array for product wish list
	vector<Order> orders_history; //array of all orders we have ever done,every part of the array contains a order we made.
	Customer() = default;
	void resizeWishlistArray();
	void resizeOrderlistArray();
	void getSum(float &sum) const;
};

#endif // !__Customer_H
