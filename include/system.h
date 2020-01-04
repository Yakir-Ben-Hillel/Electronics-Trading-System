#ifndef __System_H
#define __System_H
#pragma once
//this h file contains all the includes of the project,every cpp file calls to that h file.
#include <iostream>
#include <fstream>
#include <ostream>
#include <string.h>
using namespace std;
#include "user.h"
#include "order.h"
#include "address.h"
#include "product.h"
#include "customer.h"
#include "seller.h"
#include "FeedBack.h"
#include "Date.h"
#include "CAS.h"
#include "systemException.h"
class Address;
class Customer;
class Seller;
class User;
class System
{
public:
	//Constructors && Distructors
	//In my option the user should not set arrays sizes by himself.-Yakir
	System(User **users_array = nullptr, User *logged_in_user = nullptr,
		   unsigned int users_array_physical_size = 0,
		   unsigned int users_array_logical_size = 0);
	System(const System &other);
	~System();
	//Setters Functions.
	//Getters Functions.
	const char *getSystemName() const;
	unsigned int getCurrentID();
	const System &operator+=(User *user);
	//other methoods
	void mainMenu();
	void makeSeller();
	Address *makeAddress();
	void makeCustomer();
	bool addUserToArray(User *new_user);
	void printCustomersNames() const;
	void printOptionsAsGuest() const;
	void printSellersNames() const;
	void printCASNames() const;
	void printOptionsAsSeller() const;
	void printOptionAsCAS() const;
	void loadUsersFromFile();
	void writeUsersToFile();
	bool addFeedback(Customer *customer);
	void printOptionsAsCustomer() const;
	void makeProductForSale();
	void chooseProductToAddToCustomerWishlist();
	void makeOrder();
	void compareCustomers() const;
	void login();
	void signup();
	bool setUsersArray(User **given_users_array);
	void resizeUsersArray();
	void printOpening() const;
	void printAllAvailableSellersToGiveFeedbacks(Customer *customer);
	void printOptionsWhenAnonymous() const;
	void showProductsWithTheSameName(const char *name);

private:
	const char system_name[24] = "The Trading System";
	User **users_array = nullptr;
	User *logged_in_user = nullptr;
	int users_array_physical_size = 0;
	int users_array_logical_size = 0;
	//private methoods
	bool checkUsernameAvailability(const char *username);
};
bool isSubstring(const char *s1, const char *s2);
#endif // !__System_H
