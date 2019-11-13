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
	char *getUserName() const;
	char *getAddress() const;
	void setUserName(char *userName);
	void setPassword(char *password);
	void setAddress(char *address);

private:
	efeedback curr_fidback;
	char *userName;
	char *address;
	char password[11]; //max length of password is 10 chars,can be letter or a number
	Product **s_stock;
};

#endif // !__Seller_H
