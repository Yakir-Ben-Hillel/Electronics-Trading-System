#ifndef __Seller_H
#define __Seller_H
#include "system.h"
#include "product.h"



class Seller
{
    public:
	   enum efidback { A = 'A', B, C, D, E };//A is like 5 stars and E is like 1 star



    private:
		efidback curr_fidback;
		char* s_user_name;
		char* s_address;
		char s_password[10];//max length of password is 10 chars,can be letter or a number
		Product** s_stock;
};

#endif // !__Seller_H
