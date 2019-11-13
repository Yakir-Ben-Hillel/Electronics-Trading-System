#ifndef __Product_H
#define __Product_H

#include "system.h"

class Product
{
    public:
		enum eCategory {Children,Electricity,Office,Clothing};
		//constructors&&distructors
		Product() = default;
		Product(const char* name,float price=0,unsigned int serial=0,eCategory category);
		Product(Product& other);
		~Product();

		bool setName(const char* name);
        bool setPrice(float price);
        bool setSerialNumber(unsigned int serial);
		bool setCategory(eCategory category);

		const char* getName() const;
		float getPrice() const;
		eCategory getCategory() const;
		unsigned int getSerialNumber() const;

    private:
		eCategory p_category;
		char* p_name;
		float p_price;
		unsigned int p_serialNumber;
};


#endif