//electorincs project by Maor Ben Moshe,ID:316041466 and Yakir Ben Hillel,ID:209509348
#include "./include/system.h"
int main()
{
    System *store = new System();
    char system_name[20] = "trading-app";
    cout << "Please choose a name for your system: ";
    store->setSystemName(system_name);
    Seller *seller;
    Customer *customer;
    seller = makeSeller();
    store->addSellerToArray(seller);
    makeProductForSale(store);
    customer = makeCustomer();
    store->addCustomerToArray(customer);
    chooseProductToAddToCustomerWishlist(store);
    delete store;
}