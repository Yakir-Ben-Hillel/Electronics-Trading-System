#include "../../include/system.h"
Customer::Customer(const Customer &other) : User(other)
{
    *this = other;
}
Customer::Customer(ifstream &inFile) : User(inFile)
{
    // inFile >> *this;
}
Customer::Customer(Customer &&other) : User(std::move(other))
{
    this->c_wishList = other.c_wishList;
    this->orders_history = other.orders_history;
}
Customer::Customer(const string &username, const string &password,
                   const Address &address, const vector<Product*> &wishlist,
                   const vector<Order*> &orderHistory) noexcept(false)
    : User(username, password, address), c_wishList(wishlist), orders_history(orderHistory)
{
}

void Customer::setWishList(const vector<Product*> &wishList)
{
    this->c_wishList = wishList;
}
void Customer::SetOrderArray(const vector<Order*> &orders_array)
{
    this->orders_history = orders_array;
}
std::vector<Order*> Customer::getOrderHistory() const
{
    return this->orders_history;
}

vector<Product*> Customer::getWishList() const
{
    return c_wishList;
}

bool Customer::addProductToWishlistArray(Product &new_product)
{
    this->c_wishList.push_back(&new_product);
    return true;
}
bool Customer::AddOrderToArray(Order &given_order)
{
    this->orders_history.push_back(&given_order);
    return true;
}

void Customer::makeOrder() noexcept(false)
{
    if (this->c_wishList.size() != 0)
    {

        bool fContinue = true;
        vector<Product*> temp_list;
        vector<Product*>::iterator itr = temp_list.begin();
        vector<Product*>::iterator itrEnd = temp_list.end();

        int index, temp_index = 0;
        float price_of_order = 0;
        char answer;
        do
        {
            if (this->c_wishList.size() != 0)
            {
                int counter = 1;
                cout << "please pick from the following products the product you want to buy: " << endl;
                for (; itr != itrEnd; ++itr)
                {
                    cout << "Product number #" << counter << " " << endl;
                    cout << *itr;
                    counter++;
                }

                cout << "please enter the number of product you would like to buy: " << endl;
                cin >> index;
                temp_list.push_back(this->c_wishList[index - 1]);
                price_of_order += temp_list[temp_index]->getPrice();
                temp_index++;
                auto toDelete = this->c_wishList.begin() + (index - 1);
                this->c_wishList.erase(toDelete);
                if (this->c_wishList.size() != 0)
                {
                    cout << "do you want to buy something else?(y/n)" << endl;
                    cin >> answer;
                    fContinue = (answer == 'y' ? true : false);
                }
                else
                    fContinue = false;
            }
            else
            {
                fContinue = false;
                cout << "Wishlist is Empty." << endl;
            }
        } while (fContinue != false);
        Order* temp_order=new Order(temp_list, price_of_order);
        this->orders_history.push_back(temp_order);
        cout << temp_order;
    }
    else
    {
        cout << "Wishlist is Empty." << endl;
    }
}

bool Customer::didCustomerOrderedFromSeller(Seller &seller)
{

    unsigned int orders_array_length = this->orders_history.size();
    if (orders_array_length == 0)
        return false;
    else
    {
        vector<Order*>::iterator itrOrder = this->orders_history.begin();
        vector<Order*>::iterator itrOrderEnd = this->orders_history.end();
        vector<Product*> temp;
        for (; itrOrder != itrOrderEnd; ++itrOrder)
        {
            temp = (*itrOrder)->getList();
            vector<Product*>::iterator itrProduct = temp.begin();
            vector<Product*>::iterator itrProductEnd = temp.end();
            for (; itrProduct != itrProductEnd; ++itrProduct)
            {
                if ((*itrProduct)->getSeller() == seller)
                    return true;
            }
        }
        return false;
    }
}
void Customer::addFeedBackToSeller(Seller &seller) noexcept(false)
{
    bool can_give_a_feedback;
    can_give_a_feedback = didCustomerOrderedFromSeller(seller);
    if (can_give_a_feedback)
    {
        bool isDateValid = true;
        cin.ignore(256, '\n');
        cout << "please enter your notes about the seller: " << endl;
        string temp;
        getline(cin, temp);
        int day, month, year;
        cout << "what date is it? (format: dd/mm/yyyy)" << endl;
        cin >> day >> month >> year;
        FeedBack curr_feedback(temp, *this, Date(day, month, year));
        seller.addFeedbackToArray(curr_feedback);
    }
    else
    {
        cout << "you can't give a feedback to a seller you didn't buy from" << endl;
    }
}

const Customer &Customer::operator=(const Customer &other)
{
    if (this != &other)
    {
        (User &)*this = other;
        setWishList(other.c_wishList);
    }
    return *this;
}

bool operator<(const Customer &first, const Customer &second)
{
    float first_sum, second_sum;
    first.getSum(first_sum);
    second.getSum(second_sum);
    if (first_sum < second_sum)
        return true;
    else
        return false;
}
bool operator>(const Customer &first, const Customer &second)
{
    float first_sum, second_sum;
    first.getSum(first_sum);
    second.getSum(second_sum);
    if (first_sum > second_sum)
        return true;
    else
        return false;
}
void Customer::getSum(float &sum) const
{
    vector<Product*>::const_iterator itr = this->c_wishList.begin();
    vector<Product*>::const_iterator itrEnd = this->c_wishList.end();
    int size = this->c_wishList.size();
    for (; itr != itrEnd; ++itr)
        sum += (*itr)->getPrice();
}
void Customer::toOs(ostream &out) const
{
    if (typeid(out) != typeid(ofstream))
    {
        out << "Wishlist: " << endl;

        if (!this->c_wishList.empty())
        {
            vector<Product*>::const_iterator itrProduct = this->c_wishList.begin();
            vector<Product*>::const_iterator itrProductEnd = this->c_wishList.end();
            for (; itrProduct != itrProductEnd; ++itrProduct)
                out << *itrProduct << endl;
        }
        else
            out << "Wishlist is Empty." << endl;
        if (!this->orders_history.empty())
        {
            vector<Order*>::const_iterator itrOrder = this->orders_history.begin();
            vector<Order*>::const_iterator itrOrderEnd = this->orders_history.end();
            for (; itrOrder != itrOrderEnd; ++itrOrder)
                out << *itrOrder << endl;
        }
        else
            out << "The user didn't made any Order" << endl;
    }
}

User *Customer::clone() const
{
    return new Customer(*this);
}

bool Customer::operator==(const User &other) const
{
    if (!User::operator==(other))
        return false;
    return true;
}
