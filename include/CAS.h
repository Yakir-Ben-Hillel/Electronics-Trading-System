#ifndef __CAS
#define __CAS
#include "customer.h"
#include "seller.h"

class CAS :public Customer,public Seller 
{
   public:
   CAS(const User& user,const Customer& customer,const Seller& seller);
   CAS(const CAS& other);
   ~CAS();
};
#endif