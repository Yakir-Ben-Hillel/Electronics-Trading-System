//electorincs project by Maor Ben Moshe,ID:316041466 and Yakir Ben Hillel,ID:209509348
#include "./include/system.h"
#pragma warning (disable:4996)

int main()
{
    Seller *seller = new Seller();
    seller->setPassword("y9349931");
    cout<<seller->getPassword()<<endl;
    delete seller;
}