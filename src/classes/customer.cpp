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
                   const Address &address, vector<Product> &wishlist,
                   vector<Order> &orderHistory) noexcept(false)
    : User(username, password, address), c_wishList(wishlist), orders_history(orderHistory)
{
}

bool Customer::setWishList(const vector<Product *> wishList)
{
}
bool Customer::SetOrderArray(const vector<Order *> orders_array)
{
}

std::vector<Order> Customer::getOrderHistory() const
{
    return this->orders_history;
}

// const Order &Customer::getOrder(int location) const
// {
//     return orders_history[location];
// }

vector<Product> Customer::getWishList() const
{
    return c_wishList;
}

bool Customer::addProductToWishlistArray(const Product &new_product)
{
    this->c_wishList.push_back(new_product);
    return true;
}
bool Customer::AddOrderToArray(const Order &given_order)
{
    this->orders_history.push_back(given_order);
    return true;
}

void Customer::makeOrder() noexcept(false)
{
    if (this->c_wishList.size() != 0)
    {

        bool fContinue = true;
        vector<Product> temp_list;
        vector<Product>::iterator itr = temp_list.begin();
        vector<Product>::iterator itrEnd = temp_list.end();

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
                price_of_order += temp_list[temp_index].getPrice();
                temp_index++;
                vector<Product>::iterator toDelete = this->c_wishList.begin() + (index - 1);
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
        Order temp_order(temp_list, price_of_order, temp_index, temp_index);
        this->setOrder(temp_order);
        cout << *temp_order;
        delete temp_order;
        for (int i = 0; i < temp_index; i++)
            delete temp_list[i];
        delete[] temp_list;
    }
    else
    {
        cout << "Wishlist is Empty." << endl;
    }
}

void Customer::deleteFromWishList(int location)
{
    this->c_wishList.erase()
        //all the parts of the array are pointers, because of that we just put the address in the right pointer and free the wanted memory.
        this->c_wishList[location] = this->c_wishList[this->c_wish_logical_size - 1];
    this->c_wish_logical_size--;
}
bool Customer::didCustomerOrderedFromSeller(Seller *seller)
{

    unsigned int orders_array_length = this->getLogicSizeOfOrder();
    if (orders_array_length == 0)
        return false;
    else
    {
        for (int i = 0; i < orders_array_length; i++)
        {
            Product **products_list = this->orders_history[i]->getList();
            unsigned int order_length = this->orders_history[i]->getPhysicalSize();
            for (int j = 0; j < order_length; j++)
            {
                if (products_list[j]->getSeller() == *seller)
                    return true;
            }
        }
        return false;
    }
}
void Customer::addFeedBackToSeller(Seller *seller) noexcept(false)
{
    bool can_give_a_feedback;
    can_give_a_feedback = didCustomerOrderedFromSeller(seller);
    if (can_give_a_feedback == false)
        cout << "you can't give a feedback to a seller you didn't bought from" << endl;
    else
    {
        bool isDateValid = true;
        cin.ignore(256, '\n');
        cout << "please enter your notes about the seller: " << endl;
        char temp[256];
        cin.getline(temp, 255);
        int day, month, year;
        cout << "what date is it? (format: dd/mm/yyyy)" << endl;
        cin >> day >> month >> year;
        FeedBack *curr_feedback = new FeedBack(temp, *this, Date(day, month, year));
        seller->addFeedbackToArray(curr_feedback);
    }
}

const Customer &Customer::operator=(const Customer &other)
{
    if (this != &other)
    {
        (User &)*this = other;
        setWishList((const Product **)other.c_wishList, other.c_wish_logical_size);
        setWishListPhysicalSize(other.c_wish_physical_size);
        setWishListLogicalSize(other.c_wish_logical_size);
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
    for (int i = 0; i < this->c_wish_logical_size; ++i)
        sum += this->c_wishList[i]->getPrice();
}
void Customer::toOs(ostream &out) const
{
    if (typeid(out) != typeid(ofstream))
    {
        out << "Wishlist: " << endl;
        if (this->c_wish_logical_size != 0)
        {
            for (int i = 0; i < this->c_wish_logical_size; i++)
                out << *this->c_wishList[i] << endl;
        }
        else
            out << "Wishlist is Empty." << endl;
        if (this->order_logical_size != 0)
        {
            for (int i = 0; i < this->order_logical_size; i++)
                out << *this->orders_history[i] << endl;
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
