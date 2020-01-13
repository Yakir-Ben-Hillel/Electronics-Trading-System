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
	static char *CategoryNames[4];
	//constructors&&distructors
	Product(const string &name, eCategory category,const Seller &seller, float price) noexcept(false);
	Product(const Product &other);
	Product(Product &&other);
	~Product();
	//seters
	bool setName(const string &name);
	bool setPrice(float price);
	bool setSerialNumber(unsigned int serial);
	bool setCategory(eCategory category);
	//geters
	const string &getName() const;
	const Seller &getSeller() const;
	float getPrice() const;
	eCategory getCategory() const;
	unsigned int getSerialNumber() const;
	friend ostream &operator<<(ostream &out, const Product &product);

private:
	eCategory p_category;
	string p_name;
	float p_price;
	unsigned int p_serialNumber;
	const Seller &p_seller;
	static unsigned int counter; //for the serial number
};

#endif