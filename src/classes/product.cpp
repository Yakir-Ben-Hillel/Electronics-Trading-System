#include "../../include/system.h"
//static declaration
char *Product::CategoryNames[4] = {(char *)"Children", (char *)"Electricity", (char *)"Office", (char *)"Clothing"};
unsigned int Product::counter = 0;

Product::Product(const string &name, eCategory category,const Seller &seller, float price) noexcept(false)
    : p_serialNumber(++counter), p_seller(seller)
{
    if (name.empty() || price < 0)
        throw ProductException(name, price);
    setName(name);
    setCategory(category);
    setPrice(price);
}
Product::Product(const Product &other) : p_seller(other.p_seller)
{
    p_name = other.p_name;
    p_price = other.p_price;
    p_serialNumber = other.p_serialNumber;
    p_category = other.p_category;
}

Product::Product(Product &&other) : p_seller(other.p_seller)
{
    this->p_name = other.p_name;
    this->p_category = other.p_category;
    this->p_price = other.p_price;
    this->p_serialNumber = other.p_serialNumber;
}

bool Product::setName(const string &name)
{
    this->p_name = name;
    return true;
}

bool Product::setPrice(float price)
{
    this->p_price = price;
    return true;
}

bool Product::setSerialNumber(unsigned int serial)
{
    this->p_serialNumber = serial;
    return true;
}

bool Product::setCategory(eCategory category)
{
    if (category == Children || category == Office || category == Electricity || category == Clothing)
    {
        this->p_category = category;
        return true;
    }
    cout << "the section you have chosen is not allowed" << endl;
    cout << "please choose one of the available sections" << endl;
    return false;
}

const string &Product::getName() const
{
    return p_name;
}

float Product::getPrice() const
{
    return p_price;
}

Product::eCategory Product::getCategory() const
{
    return p_category;
}

unsigned int Product::getSerialNumber() const
{
    return p_serialNumber;
}
const Seller &Product::getSeller() const
{
    return p_seller;
}
ostream &operator<<(ostream &out, const Product &product)
{
    out << "Product name: " << product.p_name << endl;
    out << "Product category: " << product.CategoryNames[product.getCategory()] << endl;
    out << "Product Price: " << product.p_price << endl;
    out << "Product seller's name: " << product.p_seller.getName() << endl;
    return out;
}