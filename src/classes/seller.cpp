#include "../../include/system.h"
#include "../../include/seller.h"

Seller::Seller(const string &username, const string &password, const Address &address,
               const vector<Product *> &stockArray,
               const vector<FeedBack *> &feedbacksArray) noexcept(false)
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
Seller::~Seller()
{
    vector<Product *>::iterator itrProd = this->s_stock.begin();
    vector<Product *>::iterator itrProdEnd = this->s_stock.end();
    vector<FeedBack *>::iterator itrFeed = this->feedBack_array.begin();
    vector<FeedBack *>::iterator itrFeedEnd = this->feedBack_array.end();
    for (; itrProd != itrProdEnd; ++itrProdEnd)
        delete *(itrProd);
    for (; itrFeed != itrFeedEnd; ++itrFeed)
        delete *(itrFeed);
}
void Seller::setStockArray(vector<Product *> given_product_array)
{
    this->s_stock = given_product_array;
}
void Seller::setFeedbacksArray(vector<FeedBack *> given_feedBacks_array)
{
    this->feedBack_array = given_feedBacks_array;
}
vector<Product *> Seller::getStock() const
{
    return s_stock;
}
bool Seller::addProductToStockArray(Product &new_product)
{
    this->s_stock.push_back(&new_product);
    return true;
}
bool Seller::addFeedbackToArray(FeedBack &new_feedback)
{
    if (feedBack_array.capacity() == feedBack_array.size())
        feedBack_array.reserve(feedBack_array.capacity() * 2 + 1);
    this->feedBack_array.push_back(&new_feedback);
    return true;
}
vector<FeedBack *> Seller::getfeedBacksArray() const
{
    return this->feedBack_array;
}

const Seller &Seller::operator=(const Seller &other)
{
    if (this != &other)
    {
        (User &)*this = other;
        setStockArray(other.s_stock);
        setFeedbacksArray(other.feedBack_array);
    }
    return *this;
}
void Seller::toOs(ostream &out) const
{
    if (typeid(out) != typeid(ofstream))
    {
        if (this->s_stock.size() != 0)
        {
            out << "Products: " << endl;
            vector<Product *>::const_iterator itr = s_stock.begin();
            vector<Product *>::const_iterator itrEnd = s_stock.end();
            for (; itr != itrEnd; ++itr)
                out << *(*itr) << endl;
        }
        else
            out << "Has no Products" << endl;
        if (this->feedBack_array.size() != 0)
        {
            out << "Feedbacks: " << endl;
            vector<FeedBack *>::const_iterator itr = feedBack_array.begin();
            vector<FeedBack *>::const_iterator itrEnd = feedBack_array.end();

            for (; itr != itrEnd; ++itr)
                out << *(*itr) << endl;
        }
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
