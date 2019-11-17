#ifndef __ORDER_H
#define __ORDER_H

class Product;

class Order
{
public:
    Order(Product **order_list, int price, int size);
    Order(const Order &other);
    ~Order();

    bool setPrice(int price_of_order);
    bool setProductList(Product **order_list);
    bool setSize(int size);

    int getPrice() const;
    Product **getList() const;
    int getSize() const;

private:
    int price_of_order;
    Product **order_history; //pointer to array of products we have already bought.
    int size_of_list = 0;
};

#endif