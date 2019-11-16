#ifndef __Seller_H
#define __Seller_H
#include "system.h"

class FeedBack;
class Address;
class Product;

class Seller
{
public:
	enum efeedback
	{
		A = 'A',
		B,
		C,
		D,
		E
	}; //A is like 5 stars and E is like 1 star
	/*struct FeedBack
	{
		char *feedback;
		efeedback rating;
	};*/
	//Constructors && Distructors
	Seller() = default;
	Seller(char *userName, Address address, char *password, Product **stockArray, FeedBack *feedbacksArray);
	Seller(const Seller &other);
	~Seller();
	//Getters Functions.
	char *getUserName() const;
	Address getAddress() const;
	Product **getStock() const;
	FeedBack *getfeedBacksArray() const;
	//Setters Functions.
	bool setUserName(char *userName);
	bool setPassword(char *password);
	bool setAddress(Address address);
	bool setStockArray(Product **given_stock_array);
	FeedBack setFeedback(FeedBack given_feedBack);
	bool setFeedbacksArray(FeedBack *given_feedBacks_array);

private:
	char *userName;
	Address address;
	char password[11]; //max length of password is 10 chars,can be letter or a number
	Product **s_stock = nullptr;
	unsigned int stock_array_length = 0;
	FeedBack **feedBack_array = nullptr;
	unsigned int feedbacks_array_length = 0;
};

#endif // !__Seller_H

