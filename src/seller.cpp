<<<<<<< HEAD
#include "../include/system.h"
Seller::Seller(char *userName, Address* address,const char *password, Product **stockArray, FeedBack **feedbacksArray)
=======
#include "../include/includes.h"
Seller::Seller(char *userName, Address *address, const char *password, Product **stockArray, 
FeedBack **feedbacksArray,unsigned int s_size=0,unsigned int f_size=0)
>>>>>>> d079ab05329ad74033bc9574075e763b42e1add8
{
    setUserName(userName);
    setAddress(address);
    setPassword(password);
    setStockArray(stockArray);
    setFeedbacksArray(feedBack_array);
     stock_array_length = s_size;
    feedbacks_array_length = f_size;
}
Seller::Seller(const Seller &other)
{
    setUserName(other.userName);
    setAddress(other.address);
    setPassword(other.password);
    setStockArray(other.s_stock);
    setFeedbacksArray(other.feedBack_array);
    stock_array_length = other.stock_array_length;
    feedbacks_array_length = other.feedbacks_array_length;
}
Seller::Seller(Seller &&other)
{
    this->userName = other.userName;
    this->address = other.address;
    this->password = other.password;
    this->s_stock = other.s_stock;
    this->feedBack_array=other.feedBack_array;
    this->stock_array_length = other.stock_array_length;
    this->feedbacks_array_length = other.feedbacks_array_length;

    other.userName=nullptr;
    other.s_stock=nullptr;
    other.password=nullptr;
    other.address=nullptr;
    other.feedBack_array=nullptr;
}
}
Seller::~Seller()
{
    for (int i = 0; i < feedbacks_array_length; i++)
        delete feedBack_array[i];
    delete[] feedBack_array;
    for (int i = 0; i < stock_array_length; i++)
        delete s_stock[i];
    delete[] s_stock;
    delete userName;
    delete password;
}
bool Seller::setUserName(const char *givenUserName)
{
    userName = new char[strlen(givenUserName) + 1];
<<<<<<< HEAD
    strcpy(userName,givenUserName);
    return true;
}

bool Seller::setAddress(Address* givenAddress)
=======
    strcpy(userName, givenUserName);
    return true;
}

bool Seller::setAddress(Address *givenAddress)
>>>>>>> d079ab05329ad74033bc9574075e763b42e1add8
{
    address = new Address(*givenAddress);
    return true;
}
bool Seller::setPassword(const char *givenPassword)
{
    if (strlen(givenPassword) <= 10)
    {
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
    s_stock = new Product *[stock_array_length];
    for (int i = 0; i < stock_array_length; i++)
        s_stock[i] = new Product(*given_product_array[i]);
    return true;
}
<<<<<<< HEAD
FeedBack Seller::setFeedback(FeedBack* given_feedBack)
{
    FeedBack feedback(*given_feedBack);
    return feedback;
}
bool Seller::setFeedbacksArray(FeedBack **given_feedBacks_array)
{
    feedBack_array = new FeedBack*[feedbacks_array_length];
    for (int i = 0; i < feedbacks_array_length; i++)
        feedBack_array[i]=new FeedBack(*given_feedBacks_array[i]);
=======
bool Seller::setFeedbacksArray(FeedBack **given_feedBacks_array)
{
    feedBack_array = new FeedBack *[feedbacks_array_length];
    for (int i = 0; i < feedbacks_array_length; i++)
        feedBack_array[i] = new FeedBack(*given_feedBacks_array[i]);
>>>>>>> d079ab05329ad74033bc9574075e763b42e1add8
    return true;
}
const char *Seller::getUserName() const
{
    return userName;
}
Address *Seller::getAddress() const
{
<<<<<<< HEAD
    return address;
=======
    return this->address;
>>>>>>> d079ab05329ad74033bc9574075e763b42e1add8
}
