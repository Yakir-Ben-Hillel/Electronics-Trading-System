#ifndef __Seller_H
#define __Seller_H

#include "user.h"
class FeedBack;
class Product;
class Seller : virtual public User
{
public:
	//Constructors && Distructors
	Seller() = default;
	Seller(char *username, char *password, Address &address, Product **stockArray = nullptr, FeedBack **feedbacksArray = nullptr, unsigned int s_size = 0, unsigned int f_size = 0);
	Seller(const Seller &other);
	Seller(Seller &&other);
	~Seller();
	//Getters Functions.
	const char *getUserName() const;
	const char *getPassword() const;
	const Address &getAddress() const;
	Product **getStock() const;
	FeedBack **getfeedBacksArray(int &size) const;
	//Setters Functions.
	bool setUserName(char *userName);
	bool setPassword(char *password);
	bool setAddress(Address address);
	bool setStockArray(Product **given_stock_array);
	FeedBack setFeedback(FeedBack *given_feedBack);
	bool setFeedbacksArray(FeedBack **given_feedBacks_array);
	bool addProductToStockArray(Product *new_product);
	bool addFeedbackToArray(FeedBack *new_feedback);
	unsigned int getStockArraySize();
	void printSellerProducts();
	void makeProductForSale();

	const Seller &operator=(const Seller &other);
	virtual void toOs(ostream& out) const override;

protected:
	void resizeStockArray();
	void resizeFeedbackArray();
	Product **s_stock; //array of all product this seller sells.
	unsigned int stock_array_physical_length = 0;
	unsigned int stock_array_logical_length = 0;

	FeedBack **feedBack_array; //array of feedback from all of his buyers.
	unsigned int feedbacks_array_physical_length = 0;
	unsigned int feedbacks_array_logical_length = 0;
};

#endif // !__Seller_H
