#include "../..//include/system.h"
Customer::Customer(const char *username, const char *password, Address *address, const Product **wishlist,
                   unsigned int physicalSize, unsigned int logicalSize)
    : c_address(address)
{
    setName(username);
    setPassword(password);
    setWishList(wishlist, logicalSize);
    setWishListPhysicalSize(physicalSize);
    setWishListLogicalSize(logicalSize);
}

Customer::Customer(const Customer &other)
{
    setName(other.c_user_name);
    setPassword(other.c_password);
    setAddress(other.c_address);
    setWishList((const Product **)other.c_wishList, other.c_wish_logical_size);
    setWishListPhysicalSize(other.c_wish_physical_size);
    setWishListLogicalSize(other.c_wish_logical_size);
}

Customer::Customer(Customer &&other)
{
    this->c_user_name = other.c_user_name;
    this->c_wish_physical_size = other.c_wish_physical_size;
    this->c_wish_logical_size = other.c_wish_logical_size;
    this->c_address = other.c_address;
    this->c_wishList = other.c_wishList;
    this->c_password = other.c_password;
    this->orders_history = other.orders_history;

    other.orders_history = nullptr;
    other.c_address = nullptr;
    other.c_password = nullptr;
    other.c_user_name = nullptr;
    other.c_wishList = nullptr;
}

Customer::~Customer()
{
    delete[] c_user_name;
    delete[] c_password;
    delete c_address;
    for (int i = 0; i < c_wish_logical_size; i++)
    {
        delete c_wishList[i];
    }
    delete[] c_wishList;
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

bool Customer::setName(const char *userName)
{
    c_user_name = new char[strlen(userName) + 1];
    strcpy(c_user_name, userName);
    return true;
}

bool Customer::setAddress(Address *address)
{
    c_address = address;
    return true;
}

bool Customer::setPassword(const char *password)
{
    if (strlen(password) <= 10)
    {
        c_password = new char[strlen(password) + 1];
        strcpy(c_password, password);
        return true;
    }
    cout << "the password must be 10 chars max" << endl;
    return false;
}

bool Customer::setWishList(const Product **wishList, int size)
{
    c_wishList = new Product *[this->c_wish_physical_size];
    for (int i = 0; i < size; i++)
    {
        c_wishList[i] = new Product(*wishList[i]);
    }
    return true;
}

bool Customer::SetOrderArray(Order **order_array, int size)
{
    orders_history = new Order *[this->order_physical_size];
    for (int i = 0; i < size; i++)
    {
        setOrder(order_array[i]);
    }
    return true;
}

const char *Customer::getName() const
{
    return c_user_name;
}

const Address *Customer::getAddress() const
{
    return c_address;
}

const char *Customer::getPassWord() const
{
    return c_password;
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
bool Customer::setOrder(Order *curr_order)
{
    if (this->order_logical_size == this->order_physical_size)
        resizeOrderlistArray();
    orders_history[this->order_logical_size] = new Order(*curr_order);
    this->order_logical_size++;
    return true;
}
void Customer::resizeWishlistArray()
{
    int newSize = this->c_wish_physical_size * 2;
    Product **newArray = new Product *[newSize];
    memcpy(newArray, this->c_wishList, this->c_wish_logical_size * sizeof(Product *));
    for (int i = 0; i < this->c_wish_logical_size; i++)
        delete this->c_wishList[i];
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
    int newSize = this->order_physical_size * 2;
    Order **newArray = new Order *[newSize];
    memcpy(newArray, this->orders_history, this->order_logical_size * sizeof(Product *));
    for (int i = 0; i < this->order_logical_size; i++)
        delete this->orders_history[i];
    delete[] this->orders_history;
    this->order_physical_size = newSize;
    this->orders_history = newArray;
}

void Customer::makeOrder()
{
    bool fcontinue = true;
    Product **temp_list = new Product *[this->c_wish_logical_size];
    int index, temp_index = 0;
    unsigned int price_of_order=0;
    char answer;
    cout << "please pick from the following products the product you want to buy: " << endl;
    printProducts(c_wishList,c_wish_logical_size);
    do
    {
        cout << "please enter the number of product you would like to buy: " << endl;
        cin >> index;
        temp_list[temp_index] = new Product(*c_wishList[index - 1]);
        price_of_order+=temp_list[temp_index]->getPrice();
        temp_index++;
        deleteFromWishList(this->c_wishList[index-1]);
        cout<<"do you want to buy something else?(y/n)"<<endl;
        cin>>answer;
        fcontinue=(answer=='y'?true:false);
    } while (fcontinue != false);

    Order* temp_order=new Order(temp_list,price_of_order,c_wish_logical_size,temp_index);
    this->setOrder(temp_order);
    PrintOrder(temp_order);
    delete temp_order;
    delete temp_list;
}