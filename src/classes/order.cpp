#include "../../include/system.h"

Order::Order(Array<Product *> order_list, float price) noexcept(false)
    : order_products(order_list), price_of_order(price)
{
}
Order::Order(const Order &other)
    : order_products(other.order_products), price_of_order(other.price_of_order)
{
}
Order::Order(const Order &&other)
    : order_products(other.order_products), price_of_order(other.price_of_order)
{
}
bool Order::setPrice(float price_of_order)
{
    if (price_of_order < 0)
    {
        cout << "error,price cannot be negative" << endl;
        return false;
    }
    this->price_of_order = price_of_order;
    return true;
}
bool Order::setProductList(const Array<Product *> order_list) noexcept(false)
{
    this->order_products = order_list;
    return true;
}
float Order::getPrice() const
{
    return price_of_order;
}
Array<Product *> Order::getList() const
{
    return order_products;
}

bool Order::addProductToOrderList(Product &new_product)
{
    this->order_products += &new_product;
    return true;
}
ostream &operator<<(ostream &out, const Order &order)
{
    auto itr = order.getList();
    auto size = order.order_products.getSize();
    out << "the details of your order are: " << endl;
    for (int i = 0; i < size; ++i)
    {
        out << *(itr.getVal(i));
        out << endl;
    }
    out << "the final price of your order is: " << order.price_of_order << endl;
    out << "thank you for buying from us,have a nice day." << endl;
    return out;
}

const Order &Order::operator=(const Order &other)
{
    if (this != &other)
    {
        this->order_products = other.order_products;
        this->price_of_order = other.price_of_order;
    }
    return *this;
}