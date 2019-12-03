//electorincs project by Maor Ben Moshe,ID:316041466 and Yakir Ben Hillel,ID:209509348
#include "./include/system.h"
int main()
{
    System *store = new System();
    store->mainMenu();
    delete store;
}