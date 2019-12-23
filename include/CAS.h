#ifndef __CAS
#define __CAS
#include "customer.h"
#include "seller.h"

class CAS : public Customer, public Seller
{
public:
   CAS(const Customer &customer, const Seller &seller);
   CAS(const CAS &other);
   ~CAS();
   virtual void toOs(ostream& out) const override;
   //methoods
   void show(); //show the details of the customer&seller
};
#endif