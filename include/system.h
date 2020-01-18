#pragma once
#ifndef __System_H
#define __System_H
//this h file contains all the includes of the project,every cpp file calls to that h file.
using namespace std;
#include <iostream>
#include <fstream>
#include <ostream>
#include <exception>
#include <string.h>
#include <string>
#include <vector>
#include "systemException.h"
#include "address.h"
#include "Array.h"
#include "order.h"
#include "product.h"
#include "FeedBack.h"
#include "Date.h"
#include "user.h"
#include "customer.h"
#include "seller.h"
#include "CAS.h"

class User;
class System
{
public:
	//Constructors && Distructors
	//In my option the user should not set arrays sizes by himself.-Yakir
	System() = default;
	System(vector<User *> users_array,User *logged_in_user = nullptr);
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
	bool addFeedback(Customer &customer) noexcept(false);
	void printOptionsAsCustomer() const;
	void makeProductForSale();
	void chooseProductToAddToCustomerWishlist();
	void makeOrder();
	void compareCustomers() const;
	void login();
	void signup();
	void changePassWord();
	bool setUsersArray(vector<User *> given_users_array);
	void resizeUsersArray();
	void printOpening() const;
	void printAllAvailableSellersToGiveFeedbacks(Customer &customer);
	void printOptionsWhenAnonymous() const;
	void showProductsWithTheSameName();

private:
	const string system_name = "The Trading System";
	vector<User *> users_array;
	User *logged_in_user = nullptr;
	//private methoods
	bool checkUsernameAvailability(const string &username);
};
bool isSubstring(const string &s1, const string &s2);
#endif // !__System_H
