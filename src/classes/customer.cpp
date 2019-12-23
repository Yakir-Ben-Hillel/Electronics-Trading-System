#include "../..//include/system.h"
Customer::Customer(const char *username,const char *password,const Address &address,
                   const Product **wishlist,
                   const Order **orderHistory,
                   unsigned int orderHistoryPhysicalSize,
                   unsigned int orderHistoryLogicalSize,
                   unsigned int wishlistPhysicalSize,
                   unsigned int wishlistLogicalSize) : User(username, password, address)

{
    setWishList(wishlist, wishlistLogicalSize);
    SetOrderArray(orderHistory, orderHistoryLogicalSize);
    setWishListPhysicalSize(wishlistPhysicalSize);
    setWishListLogicalSize(wishlistLogicalSize);
}

Customer::Customer(const Customer &other) : User(other)
{
    *this = other;
}

Customer::Customer(Customer &&other) : User(std::move(other))
{
    this->c_wish_physical_size = other.c_wish_physical_size;
    this->c_wish_logical_size = other.c_wish_logical_size;
    this->c_wishList = other.c_wishList;
    this->orders_history = other.orders_history;

    other.orders_history = nullptr;
    other.c_wishList = nullptr;
}

Customer::~Customer()
{
    for (int i = 0; i < c_wish_logical_size; i++)
        delete c_wishList[i];
    delete[] c_wishList;
    for (int i = 0; i < order_physical_size; i++)
        delete orders_history[i];
    delete[] orders_history;
    c_wish_physical_size = c_wish_logical_size = 0;
}

bool Customer::setWishListPhysicalSize(unsigned int size)
{
    if (size < 0)
    {
        cout << "size cannot be negative" << endl;
        return false;
    }
    c_wish_physical_size = size;
    return true;
}
bool Customer::setWishListLogicalSize(unsigned int size)
{
    if (size < c_wish_physical_size)
    {
        cout << "logical size cannot be below his physical one" << endl;
        return false;
    }
    c_wish_logical_size = size;
    return true;
}

bool Customer::setName(char *userName)
{
    this->User::setName(userName);
    return true;
}

bool Customer::setAddress(Address address)
{
    this->User::setAddress(address);
    return true;
}

bool Customer::setPassword(char *password)
{
    this->User::setPassword(password);
    return true;
}

bool Customer::setWishList(const Product **wishList, int size)
{
    c_wishList = new Product *[size];
    for (int i = 0; i < size; i++)
    {
        c_wishList[i] = new Product(*wishList[i]);
    }
    return true;
}

bool Customer::SetOrderArray(const Order **order_array, int size)
{
    orders_history = new Order *[size];
    for (int i = 0; i < size; i++)
    {
        setOrder(order_array[i]);
    }
    return true;
}

const char *Customer::getName() const
{
    return User::getName();
}

const Address &Customer::getAddress() const
{
    return User::getAddress();
}

const char *Customer::getPassWord() const
{
    return User::getPassword();
}

Order **Customer::getOrderHistory() const
{
    return this->orders_history;
}

Order *Customer::getOrder(int location) const
{
    return this->orders_history[location];
}

unsigned int Customer::getLogicSizeOfOrder() const
{
    return order_logical_size;
}

unsigned int Customer::getPhySizeOfOrder() const
{
    return this->order_physical_size;
}

Product **Customer::getWishList() const
{
    return c_wishList;
}

unsigned int Customer::getWishListPhysicalSize() const
{
    return c_wish_physical_size;
}
unsigned int Customer::getWishListLogicalSize() const
{
    return c_wish_logical_size;
}
bool Customer::addProductToWishlistArray(Product *new_product)
{
    if (c_wish_logical_size == c_wish_physical_size)
        resizeWishlistArray();
    c_wishList[c_wish_logical_size] = new Product(*new_product);
    c_wish_logical_size++;
    return true;
}
bool Customer::setOrder(const Order *curr_order)
{
    if (this->order_logical_size == this->order_physical_size)
        resizeOrderlistArray();
    orders_history[this->order_logical_size] = new Order(*curr_order);
    this->order_logical_size++;
    return true;
}
void Customer::resizeWishlistArray()
{
    int newSize = this->c_wish_physical_size * 2 + 1;
    Product **newArray = new Product *[newSize];
    memcpy(newArray, this->c_wishList, this->c_wish_logical_size * sizeof(Product *));
    delete[] this->c_wishList;
    this->c_wish_physical_size = newSize;
    this->c_wishList = newArray;
}

bool Customer::setOrderListPhySize(unsigned int PhySize)
{
    if (PhySize < 0)
    {
        cout << "physical size cannot be negative" << endl;
        return false;
    }
    this->order_physical_size = PhySize;
    return true;
}

bool Customer::setOrderListLogicSize(unsigned int LogicSize)
{
    this->order_logical_size = LogicSize;
    return true;
}
void Customer::resizeOrderlistArray()
{
    int newSize = this->order_physical_size * 2 + 1;
    Order **newArray = new Order *[newSize];
    memcpy(newArray, this->orders_history, this->order_logical_size * sizeof(Order *));
    delete[] this->orders_history;
    this->order_physical_size = newSize;
    this->orders_history = newArray;
}
void Customer::makeOrder()
{
    if (this->c_wish_logical_size != 0)
    {

        bool fContinue = true;
        Product **temp_list = new Product *[this->c_wish_logical_size];
        int index, temp_index = 0;
        float price_of_order = 0;
        char answer;
        do
        {
            if (this->c_wish_logical_size != 0)
            {
                cout << "please pick from the following products the product you want to buy: " << endl;
                for (int j = 0; j < this->c_wish_logical_size; j++)
                {
                    cout << "Product number #" << j + 1 << " " << endl;
                    cout << (*c_wishList)[j];
                }

                cout << "please enter the number of product you would like to buy: " << endl;
                cin >> index;
                temp_list[temp_index] = new Product(*c_wishList[index - 1]);
                price_of_order += temp_list[temp_index]->getPrice();
                temp_index++;
                deleteFromWishList(index - 1);
                if (this->c_wish_logical_size != 0)
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
        Order *temp_order = new Order(temp_list, price_of_order, temp_index, c_wish_logical_size);
        this->setOrder(temp_order);
        showOrder(temp_order);
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
void Customer::showOrder(Order *curr)
{
    Product **temp = curr->getList();
    unsigned int size = curr->getPhysicalSize();
    cout << "the details of your order are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *temp[i];
        cout << endl;
    }

    cout << "the final price of your order is: " << curr->getPrice() << endl;
    cout << "thank you for buying from us,have a nice day." << endl;
}

void Customer::deleteFromWishList(int location)
{
    //all the parts of the array are pointers, because of that we just put the address in the right pointer and free the wanted memory.
    delete this->c_wishList[location];
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
                if (products_list[j]->getSeller() == seller)
                    return true;
            }
        }
        return false;
    }
}
void Customer::addFeedBackToSeller(Seller *seller)
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
        Date *date = new Date(day, month, year);
        FeedBack *curr_feedback = new FeedBack(temp, this, date);
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
    return false;
}

void Customer::getSum(float& sum) const
{
   for(int i=0;i<this->c_wish_logical_size;++i)
     sum+=this->c_wishList[i]->getPrice();
}