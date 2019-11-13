#ifndef __System_H
#define __System_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)
class Consumer;
class Seller;



class System
{
   public:


   private:
	   char* system_name;
	   Consumer** s_consumers_array;
	   Seller** s_sellers_array;
};
#endif
