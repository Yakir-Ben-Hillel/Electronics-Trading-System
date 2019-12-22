#include "../../include/system.h"
Seller::Seller(char *username, char *password, Address &address, Product **stockArray, FeedBack **feedbacksArray,
               unsigned int s_size, unsigned int f_size) : User(username, password, address), stock_array_physical_length(s_size),
                                                           feedbacks_array_physical_length(f_size)
{
    setStockArray(stockArray);
    setFeedbacksArray(feedBack_array);
}
Seller::Seller(const User &user, Product **stockArray,
               FeedBack **feedbacksArray,
               unsigned int s_size,
               unsigned int f_size)
    : User(user),
      stock_array_physical_length(s_size),
      feedbacks_array_physical_length(f_size)
{
    setStockArray(stockArray);
    setFeedbacksArray(feedBack_array);
}
Seller::Seller(const Seller &other) : User(other)
{
    *this = other;
}
Seller::Seller(Seller &&other) : User(std::move(other))
{
    this->s_stock = other.s_stock;
    this->feedBack_array = other.feedBack_array;
    this->stock_array_physical_length = other.stock_array_physical_length;
    this->stock_array_logical_length = other.stock_array_logical_length;
    this->feedbacks_array_physical_length = other.feedbacks_array_physical_length;
    this->feedbacks_array_logical_length = other.feedbacks_array_logical_length;

    other.s_stock = nullptr;
    other.feedBack_array = nullptr;
}

Seller::~Seller()
{
    for (int i = 0; i < feedbacks_array_physical_length; i++)
        delete feedBack_array[i];
    delete[] feedBack_array;
    for (int i = 0; i < stock_array_physical_length; i++)
        delete s_stock[i];
    delete[] s_stock;
}
bool Seller::setUserName(char *givenUserName)
{
    this->User::setName(givenUserName);
    return true;
}
bool Seller::setAddress(Address givenAddress)
{
    User::setAddress(givenAddress);
    return true;
}
bool Seller::setPassword(char *givenPassword)
{
    User::setPassword(givenPassword);
    return true;
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
    delete[] this->s_stock;
    this->stock_array_physical_length = newSize;
    this->s_stock = newArray;
}
bool Seller::addFeedbackToArray(FeedBack *new_feedback)
{
    if (this->feedbacks_array_logical_length == this->feedbacks_array_physical_length)
        resizeFeedbackArray();
    feedBack_array[this->feedbacks_array_logical_length] = new_feedback;
    this->feedbacks_array_logical_length++;
    return true;
}
void Seller::resizeFeedbackArray()
{
    int newSize = this->feedbacks_array_physical_length * 2 + 1;
    FeedBack **newArray = new FeedBack *[newSize];
    memcpy(newArray, this->feedBack_array, this->feedbacks_array_logical_length * sizeof(FeedBack *));
    delete[] feedBack_array;
    this->feedbacks_array_physical_length = newSize;
    this->feedBack_array = newArray;
}
const char *Seller::getUserName() const
{
    return User::getName();
}
const char *Seller::getPassword() const
{
    return User::getPassword();
}
const Address &Seller::getAddress() const
{
    return User::getAddress();
}

FeedBack **Seller::getfeedBacksArray(int &size) const
{
    size = this->feedbacks_array_logical_length;
    return this->feedBack_array;
}

const Seller &Seller::operator=(const Seller &other)
{
    if (this != &other)
    {
        (User &)*this = other;
        setStockArray(other.s_stock);
        setFeedbacksArray(other.feedBack_array);
        stock_array_physical_length = other.stock_array_physical_length;
        stock_array_logical_length = other.stock_array_logical_length;
        feedbacks_array_physical_length = other.feedbacks_array_physical_length;
        feedbacks_array_logical_length = other.feedbacks_array_logical_length;
    }
    return *this;
}
