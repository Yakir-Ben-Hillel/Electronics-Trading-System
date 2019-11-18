#ifndef __System_H
#define __System_H

class System
{
public:
	//Constructors && Distructors
	System() = default;
	//In my option the user should not set arrays sizes by himself.-Yakir
	System(const char *name, Customer **customers_array, Seller **sellers_array, unsigned int customers_array_size = 0, unsigned int sellers_array_size = 0);
	System(System &_nother);
	~System();
	//Setters Functions.
	bool setSystemName(const char *given_system_name);
	bool setCustomersArray(const Customer **given_customer_array);
	bool setSellersArray(const Seller **given_sellers_array);
	bool setSellersArraySize(const unsigned int newSize);
	bool setCustomersArraySize(const unsigned int newSIze);
	//Getters Functions.
	char *getSystemName();
	Customer **getCostumeArray();
	Seller **getSellersArray();
	int getSellersArraySize();
	int getCustomerArraySize();

private:
	char *system_name;
	Customer **s_customers_array;
	int customer_array_size = 0;
	Seller **s_sellers_array;
	int seller_array_size = 0;
};
#endif // !__System_H
