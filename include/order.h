#ifndef __ORDER_H
#define __ORDER_H

class Product;

class Order
{
public:
    Order() = default;
    Order(Product **order_list, float price = 0,
          unsigned int o_list_physical_size = 0, unsigned int o_list_logical_size = 0) noexcept(false);
    Order(const Order &other);
    Order(Order &&other); //
    ~Order();

    bool setPrice(float price_of_order);
    bool setProductList(Product **order_list) noexcept(false);
    bool setPhysicalSize(unsigned int physical_size);
    bool setLogicalSize(unsigned int logical_size);
    bool addProductToOrderList(Product *new_product);
    float getPrice() const;
    Product **getList() const;
    unsigned int getPhysicalSize() const;
    unsigned int getLogicalSize() const;
    friend ostream &operator<<(ostream &out, const Order &order);
    friend istream &operator>>(istream &in, Order &order);

private:
    void resizeOrderList();
    float price_of_order = 0;
    Product **order_products = nullptr; //pointer to array of products we have already bought.
    unsigned int o_list_physical_size = 0;
    unsigned int o_list_logical_size = 0;
};

#endif