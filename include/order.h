#ifndef __ORDER_H
#define __ORDER_H

class Product;

class Order
{
public:
    Order(vector<Product*> order_list, float price) noexcept(false);
    Order(const Order &other);
    Order(const Order &&other); //
    ~Order();

    bool setPrice(float price_of_order);
    bool setProductList(const vector<Product*> order_list) noexcept(false);
    bool addProductToOrderList(Product &new_product);
    float getPrice() const;
    vector<Product*> getList() const;
    const Order& operator=(const Order& other);
    friend ostream &operator<<(ostream &out, const Order &order);

private:
    void resizeOrderList();
    float price_of_order;
    vector<Product*> order_products; //pointer to array of products we have already bought.
};

#endif