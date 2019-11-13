#ifndef __Seller_H
#define __Seller_H
#include "system.h"
#include "product.h"

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
	struct FeedBack
	{
		char *feedback;
		efeedback rating;
	};
	//Constructors && Distructors
	Seller() = default;
	Seller(char *userName, char *address, char *password, Product **stockArray, FeedBack *feedbacksArray);
	Seller(const Seller &other);
	~Seller();
	//Getters Functions.
	char *getUserName() const;
	char *getAddress() const;
	Product **getStock() const;
	FeedBack *getfeedBacksArray() const;
	//Setters Functions.
	bool setUserName(char *userName);
	bool setPassword(char *password);
	bool setAddress(char *address);
	bool setStockArray(Product **given_stock_array);
	FeedBack setFeedback(FeedBack given_feedBack);
	bool setFeedbacksArray(FeedBack *given_feedBacks_array);

private:
	char *userName;
	char *address;
	char password[11]; //max length of password is 10 chars,can be letter or a number
	Product **s_stock;
	unsigned int stock_array_length = 0;
	FeedBack *feedBack_array;
	unsigned int feedbacks_array_length = 0;
};

#endif // !__Seller_H
