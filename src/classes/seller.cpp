#include "../../include/system.h"
Seller::Seller(char *userName, Address *address, const char *password,
               Product **stockArray, FeedBack **feedbacksArray,
               unsigned int s_size, unsigned int f_size)
               :address(address)
{
    setUserName(userName);
    setPassword(password);
    setStockArray(stockArray);
    setFeedbacksArray(feedBack_array);
    stock_array_physical_length = s_size;
    feedbacks_array_physical_length = f_size;
}
Seller::Seller(const Seller &other)
{
    setUserName(other.userName);
    setAddress(other.address);
    setPassword(other.password);
    setStockArray(other.s_stock);
    setFeedbacksArray(other.feedBack_array);
    stock_array_physical_length = other.stock_array_physical_length;
    stock_array_logical_length = other.stock_array_logical_length;
    feedbacks_array_physical_length = other.feedbacks_array_physical_length;
    feedbacks_array_logical_length = other.feedbacks_array_logical_length;
}
Seller::Seller(Seller &&other)
{
    this->userName = other.userName;
    this->address = other.address;
    this->password = other.password;
    this->s_stock = other.s_stock;
    this->feedBack_array = other.feedBack_array;
    this->stock_array_physical_length = other.stock_array_physical_length;
    this->stock_array_logical_length = other.stock_array_logical_length;
    this->feedbacks_array_physical_length = other.feedbacks_array_physical_length;
    this->feedbacks_array_logical_length = other.feedbacks_array_logical_length;

    other.userName = nullptr;
    other.s_stock = nullptr;
    other.password = nullptr;
    other.address = nullptr;
    other.feedBack_array = nullptr;
}

Seller::~Seller()
{
    for (int i = 0; i < feedbacks_array_physical_length; i++)
        delete feedBack_array[i];
    delete[] feedBack_array;
    for (int i = 0; i < stock_array_physical_length; i++)
        delete s_stock[i];
    delete address;
    delete[] s_stock;
    delete[] userName;
    delete[] password;
}
bool Seller::setUserName(const char *givenUserName)
{
    userName = new char[strlen(givenUserName) + 1];
    strcpy(userName, givenUserName);
    return true;
}

bool Seller::setAddress(Address *givenAddress)
{
    address = givenAddress;
    return true;
}
bool Seller::setPassword(const char *givenPassword)
{
    if (strlen(givenPassword) <= 10)
    {
        password = new char[(strlen(givenPassword) + 1)];
        strcpy(password, givenPassword);
        return true;
    }
    else
    {
        cout << "Maximum password length is 10." << endl;
        return false;
    }
}
bool Seller::setStockArray(Product **given_product_array)
{
    s_stock = new Product *[stock_array_physical_length];
    for (int i = 0; i < stock_array_physical_length; i++)
        s_stock[i] = new Product(*given_product_array[i]);
    return true;
}
FeedBack Seller::setFeedback(FeedBack *given_feedBack)
{
    FeedBack feedback(*given_feedBack);
    return feedback;
}
bool Seller::setFeedbacksArray(FeedBack **given_feedBacks_array)
{
    feedBack_array = new FeedBack *[feedbacks_array_physical_length];
    for (int i = 0; i < feedbacks_array_physical_length; i++)
        feedBack_array[i] = new FeedBack(*given_feedBacks_array[i]);
    return true;
}
Product **Seller::getStock() const
{
    return s_stock;
}
unsigned int Seller::getStockArraySize()
{
    return stock_array_logical_length;
}
bool Seller::addProductToStockArray(Product *new_product)
{
    if (stock_array_logical_length == stock_array_physical_length)
        resizeStockArray();
    s_stock[stock_array_logical_length] = new_product;
    stock_array_logical_length++;
    return true;
}
void Seller::resizeStockArray()
{
    int newSize = this->stock_array_physical_length * 2 + 1;
    Product **newArray = new Product *[newSize];
    memcpy(newArray, this->s_stock, this->stock_array_logical_length * sizeof(Product *));
    for (int i = 0; i < this->stock_array_logical_length; i++)
        delete this->s_stock[i];
    delete[] this->s_stock;
    this->stock_array_physical_length = newSize;
    this->s_stock = newArray;
}
const char *Seller::getUserName() const
{
    return userName;
}
const char *Seller::getPassword() const
{
    return password;
}
Address *Seller::getAddress() const
{
    return address;
}
