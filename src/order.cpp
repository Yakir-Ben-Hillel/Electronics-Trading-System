#include "../include/system.h"

Order::Order(Product **order_list, int price, int size)
{
    setProductList(order_list);
    setPrice(price);
    setSize(size);
}
Order::Order(const Order &other)
{
    setProductList(other.order_history);
    setPrice(other.price_of_order);
    setSize(other.size_of_list);
}
Order::~Order()
{
    for (int i = 0; i < this->size_of_list; i++)
    {
        delete[](order_history)[i];
    }
    delete[] order_history;
}

bool Order::setPrice(int price_of_order)
{
    if (price_of_order < 0)
    {
        cout << "error,price cannot be negative" << endl;
        return false;
    }
    this->price_of_order = price_of_order;
    return true;
}
bool Order::setProductList(Product **order_list)
{
    this->order_history = new Product *[this->size_of_list];
    for (int i = 0; i < this->size_of_list; i++)
    {
        this->order_history[i] = new Product(*order_list[i]);
    }
    return true;
}
bool Order::setSize(int size)
{
    if (size < 0)
    {
        cout << "error! size cannot be negative!" << endl;
        return false;
    }
    this->size_of_list = size;
    return true;
}
int Order::getPrice() const
{
    return price_of_order;
}
Product **Order::getList() const
{
    return order_history;
}
int Order::getSize() const
{
    return size_of_list;
}