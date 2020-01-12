#include "../../include/system.h"
Seller::Seller(const string &username, const string &password, const Address &address,
               vector<Product> &stockArray,
               vector<FeedBack> &feedbacksArray) noexcept(false)
    : User(username, password, address), s_stock(stockArray), feedBack_array(feedBack_array)
{
}
Seller::Seller(const Seller &other) : User(other)
{
    *this = other;
}
Seller::Seller(ifstream &inFile) : User(inFile)
{
}
Seller::Seller(Seller &&other) : User(std::move(other))
{
    this->s_stock = other.s_stock;
    this->feedBack_array = other.feedBack_array;
}

bool Seller::setStockArray(vector<Product> given_product_array)
{
    this->s_stock = given_product_array;
}
FeedBack Seller::setFeedback(FeedBack *given_feedBack)
{
    return FeedBack(*given_feedBack);
}
bool Seller::setFeedbacksArray(vector<FeedBack> given_feedBacks_array)
{
    this->feedBack_array = given_feedBacks_array;
}
vector<Product> Seller::getStock() const
{
    return s_stock;
}
bool Seller::addProductToStockArray(Product &new_product)
{
    this->s_stock.push_back(new_product);
    return true;
}
bool Seller::addFeedbackToArray(FeedBack &new_feedback)
{
    this->feedBack_array.push_back(new_feedback);
    return true;
}
FeedBack **Seller::getfeedBacksArray() const
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
void Seller::toOs(ostream &out) const
{
    if (typeid(out) != typeid(ofstream))
    {
        out << "Products: " << endl;
        if (this->stock_array_logical_length != 0)
            for (int i = 0; i < this->stock_array_logical_length; i++)
                out << *this->s_stock[i];
        else
            out << "Has no Products" << endl;
        out << "Feedbacks: " << endl;
        if (this->feedbacks_array_logical_length != 0)
            for (int i = 0; i < this->feedbacks_array_logical_length; i++)
                out << *this->feedBack_array[i];
        else
            out << "Has no Feedbacks" << endl;
    }
}

User *Seller::clone() const
{
    return new Seller(*this);
}

bool Seller::operator==(const User &other) const
{
    if (!User::operator==(other))
        return false;
    return true;
}
