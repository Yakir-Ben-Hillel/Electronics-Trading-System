#ifndef __Product_H
#define __Product_H

class Seller;

class Product
{
public:
	enum eCategory
	{
		Children,
		Electricity,
		Office,
		Clothing
	};
	//constructors&&distructors
	Product() = default;
	Product(const char *name, eCategory category,Seller* given_seller_name, unsigned int serial = 0,float price = 0);
	Product(const Product &other);
	~Product();
	//seters
	bool setName(const char *name);
	bool setPrice(float price);
	bool setSerialNumber(unsigned int serial);
	bool setCategory(eCategory category);
	bool setSellerName(Seller* seller);
	//geters
	const char *getName() const;
	Seller* getSellerName() const;
	float getPrice() const;
	eCategory getCategory() const;
	unsigned int getSerialNumber() const;

private:
	eCategory p_category;
	char *p_name;
	float p_price;
	unsigned int p_serialNumber;
	Seller* p_seller;
};

#endif