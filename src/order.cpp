#include "../include/includes.h"

Order::Order(Product **order_list, int price=0, int size=0)
{
    setProductList(order_list);
    setPrice(price);
    setSize(size);
}
Order::Order(const Order &other)
{
    setProductList(other.order_products);
    setPrice(other.price_of_order);
    setSize(other.size_of_list);
}
Order::Order(Order &&other)
{
    this->price_of_order=other.price_of_order;
    this->size_of_list=other.size_of_list;
    this->order_products=other.order_products;
    other.order_products=nullptr;
}
Order::~Order()
{
    for (int i = 0; i < this->size_of_list; i++)
    {
        delete[](order_products)[i];
    }
    delete[] order_products;
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
    this->order_products = new Product *[this->size_of_list];
    for (int i = 0; i < this->size_of_list; i++)
    {
        this->order_products[i] = new Product(*order_list[i]);
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
    return order_products;
}
int Order::getSize() const
{
    return size_of_list;
}