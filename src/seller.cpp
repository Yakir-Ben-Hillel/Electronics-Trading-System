#include "../include/seller.h"
bool Seller::setUserName(char *givenUserName)
{
    userName = new char[strlen(givenUserName) + 1];
    strcpy(givenUserName, userName);
    return true;
}

bool Seller::setAddress(char *givenAddress)
{
    address = new char[strlen(givenAddress) + 1];
    strcpy(givenAddress, address);
    return true;
}
bool Seller::setPassword(char *givenPassword)
{
    if (strlen(givenPassword) <= 10)
    {
        strcpy(givenPassword, password);
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
Seller::FeedBack Seller::setFeedback(Seller::FeedBack given_feedBack)
{
    FeedBack feedback;
    feedback.feedback = new char[strlen(given_feedBack.feedback)];
    return feedback;
}
bool Seller::setFeedbacksArray(Seller::FeedBack *given_feedBacks_array)
{
    feedBack_array = new FeedBack[feedbacks_array_length];
    for (int i = 0; i < feedbacks_array_length; i++)
        feedBack_array[i] = Seller::setFeedback(given_feedBacks_array[i]);
    return true;
}
char *Seller::getUserName() const
{
    return userName;
}
char *Seller::getAddress() const
{
    return address;
}
