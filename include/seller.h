#ifndef __Seller_H
#define __Seller_H

class FeedBack;
class Address;
class Product;
class Seller
{
public:
	//Constructors && Distructors
	Seller() = default;
	Seller(char *userName, Address *address, const char *password,
		   Product **stockArray = nullptr,
		   FeedBack **feedbacksArray = nullptr, unsigned int s_size = 0,
		   unsigned int f_size = 0);
	Seller(const Seller &other);
	Seller(Seller &&other);
	~Seller();
	//Getters Functions.
	const char *getUserName() const;
	const char *getPassword() const;
	Address *getAddress() const;
	Product **getStock() const;
	FeedBack **getfeedBacksArray() const;
	//Setters Functions.
	bool setUserName(const char *userName);
	bool setPassword(const char *password);
	bool setAddress(Address *address);
	bool setStockArray(Product **given_stock_array);
	FeedBack setFeedback(FeedBack *given_feedBack);
	bool setFeedbacksArray(FeedBack **given_feedBacks_array);
	bool addProductToStockArray(Product *new_product);
	bool addFeedbackToArray(FeedBack *new_feedback);
	unsigned int getStockArraySize();
	void printSellerProducts();
	void makeProductForSale();

private:
	char *userName;
	void resizeStockArray();
	void resizeFeedbackArray();
	Address *address;  //pointer to class address
	char *password;	//max length of password is 10 chars,can be letter or a number
	Product **s_stock; //array of all product this seller sells.
	unsigned int stock_array_physical_length = 0;
	unsigned int stock_array_logical_length = 0;

	FeedBack **feedBack_array; //array of feedback from all of his buyers.
	unsigned int feedbacks_array_physical_length = 0;
	unsigned int feedbacks_array_logical_length = 0;
};

#endif // !__Seller_H
