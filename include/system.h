#ifndef __System_H
#define __System_H
#pragma once
//this h file contains all the includes of the project,every cpp file calls to that h file.
#include <iostream>
#include <string.h>
using namespace std;

#include "./order.h"
#include "./address.h"
#include "./product.h"
#include "./customer.h"
#include "./seller.h"
#include "./FeedBack.h"
#include "./Date.h"
class Customer;
class Seller;
class System
{
public:
	//Constructors && Distructors
	//In my option the user should not set arrays sizes by himself.-Yakir
	System(Customer **customers_array = nullptr, Customer *logged_in_customer = nullptr,
		   Seller *logged_in_seller = nullptr, Seller **sellers_array = nullptr,
		   unsigned int customers_array_physical_size = 0,
		   unsigned int customers_array_logical_size = 0,
		   unsigned int sellers_array_physical_size = 0,
		   unsigned int sellers_array_logical_size = 0);
	System(const System &other);
	~System();
	//Setters Functions.
	bool setCustomersArray(const Customer **given_customer_array);
	bool setSellersArray(const Seller **given_sellers_array);
	//Getters Functions.
	const char *getSystemName() const;
	Customer **getCostumeArray();
	Seller **getSellersArray();
	Customer *getLoggedInCustomer() const;
	Seller *getLoggedInSeller() const;
	int getSellersArraySize();
	int getCustomerArraySize();
	unsigned int getCurrentID();
	//other methoods
	bool addSellerToArray(Seller *seller);
	bool addCustomerToArray(Customer *customer);
	void mainMenu();
	void makeSeller();
	Address *makeAddress();
	void makeCustomer();
	void printCustomersNames();
	void printOptionsAsGuest();
	void printSellersNames();
	void makeProductForSale();
	void chooseProductToAddToCustomerWishlist();
	void makeOrder();
	void login();
	void signup();
	void printOpening();
	void printAllAvailableSellersToGiveFeedbacks(Customer *customer);
	void printOptionsAsCustomer();
	void printOptionsAsSeller();
	void showProductsWithTheSameName(const char *name);

private:
	const char system_name[24] = "Electronic Trade System";
	Customer *logged_in_customer; //Use only for pointing this variable is never initialized.
	Customer **s_customers_array;
	int customer_array_physical_size = 0;
	int customer_array_logical_size = 0;
	Seller *logged_in_seller; //Use only for pointing this variable is never initialized.
	Seller **s_sellers_array;
	int seller_array_physical_size = 0;
	int seller_array_logical_size = 0;
	//private methoods
	bool setSellersArrayPhysicalSize(const unsigned int newSize);
	bool setCustomersArrayPhysicalSize(const unsigned int newSIze);
	bool setSellersArrayLogicalSize(const unsigned int newSize);
	bool setCustomersArrayLogicalSize(const unsigned int newSIze);
	void customerLogin();
	void sellerLogin();

	void resizeSellersArray();
	void resizeCustomersArray();
};

#endif // !__System_H
