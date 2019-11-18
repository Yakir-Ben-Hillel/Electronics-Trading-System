<<<<<<< HEAD
#include "../include/seller.h"
Seller::Seller(char *userName, Address *address, const char *password, Product **stockArray, FeedBack **feedbacksArray)
=======
#include "../include/includes.h"
Seller::Seller(char *userName, Address* address,const char *password, Product **stockArray, FeedBack **feedbacksArray)
>>>>>>> Maor
{
    setUserName(userName);
    setAddress(address);
    setPassword(password);
    setStockArray(stockArray);
    setFeedbacksArray(feedBack_array);
}
Seller::Seller(const Seller &other)
{
    setUserName(other.userName);
    setAddress(other.address);
    setPassword(other.password); //Might need to fix that.
    setStockArray(other.s_stock);
    setFeedbacksArray(other.feedBack_array);
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
    strcpy(userName, givenUserName);
    return true;
}

bool Seller::setAddress(Address *givenAddress)
=======
    strcpy(userName,givenUserName);
    return true;
}

bool Seller::setAddress(Address* givenAddress)
>>>>>>> Maor
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
bool Seller::setFeedbacksArray(FeedBack **given_feedBacks_array)
{
    feedBack_array = new FeedBack *[feedbacks_array_length];
    for (int i = 0; i < feedbacks_array_length; i++)
        feedBack_array[i] = new FeedBack(*given_feedBacks_array[i]);
=======
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
>>>>>>> Maor
    return true;
}
const char *Seller::getUserName() const
{
    return userName;
}
Address* Seller::getAddress() const
{
    return *address;
}
