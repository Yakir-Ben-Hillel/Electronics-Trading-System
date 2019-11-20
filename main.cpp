//electorincs project by Maor Ben Moshe,ID:316041466 and Yakir Ben Hillel,ID:209509348
#include "./include/system.h"
int main()
{
    System *store = new System();
    char system_name[20];
    cout << "Please choose a name for your system: ";
    cin.getline(system_name, 19);
    store->setSystemName(system_name);
    Seller *seller;
    seller = makeSeller();
    store->addSellerToArray(seller);
    makeProduct(store);
    printSellersNames(store);
    delete store;
}