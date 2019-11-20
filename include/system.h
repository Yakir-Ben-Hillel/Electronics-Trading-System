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
	System() = default;
	//In my option the user should not set arrays sizes by himself.-Yakir
	System(const char *name, Customer **customers_array, Seller **sellers_array,
		   unsigned int customers_array_physical_size = 0,
		   unsigned int customers_array_logical_size = 0,
		   unsigned int sellers_array_physical_size = 0,
		   unsigned int sellers_array_logical_size = 0);
	System(const System &other);
	~System();
	//Setters Functions.
	bool setSystemName(const char *given_system_name);
	bool setCustomersArray(const Customer **given_customer_array);
	bool setSellersArray(const Seller **given_sellers_array);
	//Getters Functions.
	char *getSystemName();
	Customer **getCostumeArray();
	Seller **getSellersArray();
	int getSellersArraySize();
	int getCustomerArraySize();
	unsigned int getCurrentID();
	bool addSellerToArray(Seller *seller);

private:
	char *system_name;
	Customer **s_customers_array;
	int customer_array_physical_size = 0;
	int customer_array_logical_size = 0;
	Seller **s_sellers_array;
	int seller_array_physical_size = 0;
	int seller_array_logical_size = 0;
	bool setSellersArrayPhysicalSize(const unsigned int newSize);
	bool setCustomersArrayPhysicalSize(const unsigned int newSIze);
	bool setSellersArrayLogicalSize(const unsigned int newSize);
	bool setCustomersArrayLogicalSize(const unsigned int newSIze);

	void resizeSellersArray();
};
void mainMenu();
Seller *makeSeller();
void printOptions();
void printSellersNames(System *system);
void makeProduct(System *system);
#endif // !__System_H
