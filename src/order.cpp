#include "../include/system.h"

Order::Order(Product **order_list, int price,
             unsigned int physical_size, unsigned int logical_size)
{
    setProductList(order_products);
    setPrice(price);
    setPhysicalSize(physical_size);
}
Order::Order(const Order &other)
{
    setProductList(other.order_products);
    setPrice(other.price_of_order);
    setPhysicalSize(other.o_list_physical_size);
}
Order::Order(Order &&other)
{
    this->price_of_order = other.price_of_order;
    this->o_list_physical_size = other.o_list_physical_size;
    this->order_products = other.order_products;
    other.order_products = nullptr;
}
Order::~Order()
{
    for (int i = 0; i < this->o_list_physical_size; i++)
    {
        delete (order_products)[i];
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
    this->order_products = new Product *[o_list_physical_size];
    for (int i = 0; i < this->o_list_physical_size; i++)
    {
        this->order_products[i] = new Product(*order_list[i]);
    }
    return true;
}
bool Order::setPhysicalSize(unsigned int physical_size)
{
    if (physical_size < 0)
    {
        cout << "error! size cannot be negative!" << endl;
        return false;
    }
    this->o_list_physical_size = physical_size;
    return true;
}
bool Order::setLogicalSize(unsigned int logical_size)
{
    if (logical_size < this->o_list_physical_size)
    {
        cout << "error! size cannot be negative!" << endl;
        return false;
    }
    this->o_list_logical_size = logical_size;
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
unsigned int Order::getPhysicalSize() const
{
    return o_list_physical_size;
}
unsigned int Order::getLogicalSize() const
{
    return o_list_logical_size;
}

bool Order::addProductToOrderList(Product *new_product)
{
    if (o_list_logical_size == o_list_physical_size)
        resizeOrderList();
    order_products[o_list_logical_size] = new_product;
    o_list_logical_size++;
    return true;
}
void Order::resizeOrderList()
{
    int newSize = this->o_list_physical_size * 2 + 1;
    Product **newArray = new Product *[newSize];
    memcpy(newArray, this->order_products,
           this->o_list_logical_size * sizeof(Product *));
    for (int i = 0; i < this->o_list_logical_size; i++)
        delete this->order_products[i];
    delete[] this->order_products;
    this->o_list_physical_size = newSize;
    this->order_products = newArray;
}
