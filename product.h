#ifndef __Product_H
#define __Product_H

#include "system.h"

class Product
{
    public:
		enum eCategory {Children,Electricity,Office,Clothing};

    private:
		eCategory p_category;
		char* p_name;
		float p_price;
		unsigned int p_serialNumber;
};


#endif