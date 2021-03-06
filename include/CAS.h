#pragma once
#ifndef __CAS
#define __CAS
#include "customer.h"
#include "seller.h"

class CAS : public Customer, public Seller
{
public:
   CAS(const string &username, const string &password, Address &address)
   noexcept(false);
   CAS(const Customer &customer, const Seller &seller);
   CAS(const CAS &other);
   CAS(const CAS &&other);
   CAS(ifstream &inFile);
   virtual ~CAS();
   // friend istream &operator>>(istream &in, CAS &cas);
   virtual bool operator==(const User &other) const;
   virtual void toOs(ostream &out) const override;
   virtual User *clone() const override final;
};
#endif