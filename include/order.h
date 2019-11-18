#ifndef __ORDER_H
#define __ORDER_H

class Product;

class Order
{
public:
    Order() = default;
    Order(Product **order_list, int price=0, int size=0);
    Order(const Order &other);
    Order(Order &&other);//
    ~Order();

    bool setPrice(int price_of_order);
    bool setProductList(Product **order_list);
    bool setSize(int size);

    int getPrice() const;
    Product **getList() const;
    int getSize() const;

private:
    int price_of_order=0;
    Product **order_products; //pointer to array of products we have already bought.
    int size_of_list = 0;
};

#endif