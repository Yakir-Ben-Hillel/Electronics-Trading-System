//electorincs project by Maor Ben Moshe,ID:316041466 and Yakir Ben Hillel,ID:209509348
#include "./include/system.h"
int main()
{
    System *store = new System();
    printf("welcome to %s\n", store->getSystemName());
    Seller *seller;
    Customer *customer;
    seller = store->makeSeller();
    store->addSellerToArray(seller);
    store->makeProductForSale();
    customer = store->makeCustomer();
    store->addCustomerToArray(customer);
    store->chooseProductToAddToCustomerWishlist();
    delete store;
}