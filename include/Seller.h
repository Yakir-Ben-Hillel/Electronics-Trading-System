#include <iostream>
#ifndef __SELLER__
#define __SELLER__
class Seller
{
    enum eUserType
    {
        SELLER
    };

private:
    char username[20], password[10], address[20];
    char **feedbacks = nullptr;
};
#endif