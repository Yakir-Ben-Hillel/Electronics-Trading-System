#ifndef __System_H
#define __System_H

#include <iostream>
#include <string.h>
#include "costumer.h"
#include "seller.h"
using namespace std;

#pragma warning(disable : 4996)

class System
{
public:
	//Constructors && Distructors
	System() = default;
	//In my option the user should not set arrays sizes by himself.-Yakir
	System(const char *name, Costumer **costumers_array, Seller **sellers_array, unsigned int costumers_array_size = 0, unsigned int sellers_array_size = 0);
	System(System &_nother);
	~System();
	//Setters Functions.
	bool setSystemName(const char *given_system_name);
	bool setCostumersArray(const Costumer **given_costumer_array);
	bool setSellersArray(const Seller **given_sellers_array);
	bool setSellersArraySize(const unsigned int newSize);
	bool setCostumersArraySize(const unsigned int newSIze);
	//Getters Functions.
	char *getSystemName();
	Costumer **getCostumeArray();
	Seller **getSellersArray();
	int getSellersArraySize();
	int getCostumerArraySize();

private:
	char *system_name;
	Costumer **s_costumers_array;
	int costumer_array_size = 0;
	Seller **s_sellers_array;
	int seller_array_size = 0;
};
#endif // !__System_H
