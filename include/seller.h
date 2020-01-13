#ifndef __Seller_H
#define __Seller_H

#include "user.h"
class Address;
class FeedBack;
class Product;
class Seller : virtual public User
{
public:
	//Constructors && Distructors
	Seller(const string &username, const string &password, const Address &address,
		   const vector<Product> &stockArray = vector<Product>(),
		   const vector<FeedBack> &feedbacksArray = vector<FeedBack>()) noexcept(false);
	Seller(const Seller &other);
	Seller(ifstream &inFile);
	Seller(Seller &&other);
	virtual ~Seller();
	virtual User *clone() const override;
	//Getters Functions.
	vector<Product> getStock() const;
	vector<FeedBack> getfeedBacksArray() const;
	//Setters Functions.
	void setStockArray(vector<Product> given_stock_array);
	void setFeedbacksArray(vector<FeedBack> given_feedBacks_array);
	bool addProductToStockArray(Product &new_product);
	bool addFeedbackToArray(FeedBack &new_feedback);
	unsigned int getStockArraySize();
	void printSellerProducts();
	void makeProductForSale() noexcept(false);
	/*Operators*/
	const Seller &operator=(const Seller &other);
	bool operator==(const User &other) const;
	virtual void toOs(ostream &out) const override;

protected:
	Seller() = default;
	void resizeStockArray();
	void resizeFeedbackArray();
	FeedBack setFeedback(FeedBack &given_feedBack);
	vector<Product> s_stock;		 //array of all product this seller sells.
	vector<FeedBack> feedBack_array; //array of feedback from all of his buyers.
};

#endif // !__Seller_H
