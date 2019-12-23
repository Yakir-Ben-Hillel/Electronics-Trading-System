#ifndef __CAS
#define __CAS
#include "customer.h"
#include "seller.h"

class CAS : public Customer, public Seller
{
public:
   CAS(char *username, char *password, Address &address);
   CAS(const User &user, const Customer &customer, const Seller &seller);
   CAS(const User &user);
   CAS(const CAS &other);
   virtual ~CAS();

   //methoods
   void show(); //show the details of the customer&seller
};
#endif