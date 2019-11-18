//electorincs project by Maor Ben Moshe,ID:316041466 and Yakir Ben Hillel,ID:209509348
#include "./include/system.h"
#pragma warning (disable:4996)

int main()
{
    Seller *seller = new Seller();
    cout<<seller->getAddress()<<endl;
    delete seller;
}