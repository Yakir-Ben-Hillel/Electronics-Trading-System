#ifndef __Consumer_H
#define __Consumer_H

#include "system.h"
#include "product.h"
#include "seller.h"

class Consumer
{
  



    private:
		char* c_user_name;
		char* c_address;
		char c_password[10];//max length of password is 10 chars,can be letter or a number
		Product** c_wishList;//pointer array for product wish list
};

#endif // !__Consumer_H

