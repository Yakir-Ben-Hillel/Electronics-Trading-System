#ifndef __System_H
#define __System_H
#pragma once
//this h file contains all the includes of the project,every cpp file calls to that h file.
#include <iostream>
#include <fstream>
#include <ostream>
#include <string.h>
#include <exception>
#include <string>
#include <vector>
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
class User;
class System
{
public:
	//Constructors && Distructors
	//In my option the user should not set arrays sizes by himself.-Yakir
	System() = default;
	System(vector<User *> users_array, User *logged_in_user = nullptr);
	System(const System &other);
	~System();
	//Setters Functions.
	//Getters Functions.
	const string &getSystemName() const;
	const System &operator+=(User *user);
	//other methoods
	void mainMenu();
	Address *makeAddress() noexcept(false);
	bool addUserToArray(User *new_user);
	void printCustomersNames() const;
	void printOptionsAsGuest() const;
	void printSellersNames() const;
	void printCASNames() const;
	void printOptionsAsSeller() const;
	void printOptionAsCAS() const;
	void loadUsersFromFile();
	void writeUsersToFile();
	bool addFeedback(Customer *customer) noexcept(false);
	void printOptionsAsCustomer() const;
	void makeProductForSale();
	void chooseProductToAddToCustomerWishlist();
	void makeOrder();
	void compareCustomers() const;
	void login();
	void signup();
	bool setUsersArray(vector<User *> given_users_array);
	void resizeUsersArray();
	void printOpening() const;
	void printAllAvailableSellersToGiveFeedbacks(Customer *customer);
	void printOptionsWhenAnonymous() const;
	void showProductsWithTheSameName(const string &name);

private:
	const string system_name = "The Trading System";
	vector<User *> users_array;
	User *logged_in_user = nullptr;
	//private methoods
	bool checkUsernameAvailability(const char *username);
};
bool isSubstring(const char *s1, const char *s2);
#endif // !__System_H
