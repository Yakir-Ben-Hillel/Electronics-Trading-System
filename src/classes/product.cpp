#include "../../include/system.h"
//static declaration
char *Product::CategoryNames[4] = {(char *)"Children", (char *)"Electricity", (char *)"Office", (char *)"Clothing"};
unsigned int Product::counter = 0;

Product::Product(const char *name, eCategory category, Seller *seller, float price)
    : p_serialNumber(++counter)
{
    setName(name);
    setCategory(category);
    setPrice(price);
    setSeller(seller);
}
Product::Product(istream &inFile)
{
    inFile >> *this;
}
Product::Product(const Product &other)
{
    p_name = new char[strlen(other.p_name) + 1];
    strcpy(p_name, other.p_name);
    p_price = other.p_price;
    p_serialNumber = other.p_serialNumber;
    p_category = other.p_category;
    setSeller(other.p_seller);
}

Product::Product(Product &&other)
{
    this->p_seller = other.p_seller;
    this->p_name = other.p_name;
    this->p_category = other.p_category;
    this->p_price = other.p_price;
    this->p_serialNumber = other.p_serialNumber;

    other.p_seller = nullptr;
    other.p_name = nullptr;
}

Product::~Product()
{
    delete[] p_name;
}

bool Product::setName(const char *name)
{
    p_name = new char[strlen(name) + 1];
    strcpy(p_name, name);
    return true;
}

bool Product::setPrice(float price)
{
    if (price < 0)
    {
        cout << "price are not able to be negative!" << endl;
        return false;
    }
    p_price = price;
    return true;
}

bool Product::setSerialNumber(unsigned int serial)
{
    p_serialNumber = serial;
    return true;
}

bool Product::setCategory(eCategory category)
{
    if (category == Children || category == Office || category == Electricity || category == Clothing)
    {
        p_category = category;
        return true;
    }
    cout << "the section you have chosen is not allowed" << endl;
    cout << "please choose one of the available sections" << endl;
    return false;
}
bool Product::setSeller(const Seller *seller)
{
    p_seller = seller;
    return true;
}

const char *Product::getName() const
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
const Seller *Product::getSeller() const
{
    return p_seller;
}
ostream &operator<<(ostream &out, const Product &product)
{
    if (typeid(out) == typeid(ofstream))
    {
        out << product.p_name << " " << product.CategoryNames[product.getCategory()]
            << " " << product.p_price << " " << *product.p_seller;
    }
    else
    {
        out << "Product name: " << product.p_name << endl;
        out << "Product category: " << product.CategoryNames[product.getCategory()] << endl;
        out << "Product Price: " << product.p_price << endl;
        out << "Product seller's name: " << product.p_seller->getUserName() << endl;
    }
    return out;
}
istream &operator>>(istream &in, Product &product)
{
    char productName[21];
    Seller *sellerTemp = new Seller(*product.p_seller);
    char category[12];
    Product::eCategory eCategory;
    float price;
    in >> productName >> category >> price >> *sellerTemp;
    product.setName(productName);
    if (strcmp(category, "Children") == 0)
        eCategory = Product::Children;
    else if (strcmp(category, "Electricity") == 0)
        eCategory = Product::Electricity;
    else if (strcmp(category, "Office") == 0)
        eCategory = Product::Office;
    else
        eCategory = Product::Clothing;
    product.setCategory(eCategory);
    product.setPrice(price);
    product.setSeller(sellerTemp);
    return in;
}