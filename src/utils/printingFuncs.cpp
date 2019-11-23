#include "../../include/system.h"
void System::printOpening()
{
    cout << "**********************************************" << endl;
    cout << "**********************************************" << endl;
    cout << " #########   ##    ##    ########     ########" << endl;
    cout << "##           ##    ##   ##      ##    ##    ##" << endl;
    cout << " ##          ##    ##  ##        ##   ##   ##" << endl;
    cout << " #########   ########  ##        ##   ######" << endl;
    cout << "        ##   ##    ##   ##      ##    ##" << endl;
    cout << "       ##    ##    ##    ########     ##" << endl;
    cout << " #######     ##    ##                 ##" << endl;
    cout << "**********************************************" << endl;
    cout << "**********************************************" << endl;
    cout << endl;
}
void System::printOptionsAsGuest()
{
    cout << "1) Login." << endl;
    cout << "2) SignUp." << endl;
    cout << "3) Print all Customers names." << endl;
    cout << "4) Print all Sellers names." << endl;
    cout << "5) Exit." << endl;
    cout << "Please insert the number of your chosen option: ";
}

void System::printOptionsAsCustomer()
{
    cout << "1) Add Product to your Wishlist." << endl;
    cout << "2) Add Feedback to a Seller." << endl;
    cout << "3) Make an Order." << endl;
    cout << "4) Print all Sellers names." << endl;
    cout << "5) Search for a Product" << endl;
    cout << "6) Logout." << endl;
    cout << "7) Exit" << endl;
}
void System::printOptionsAsSeller()
{
    cout << "1) Add a Product." << endl;
    cout << "2) View your Feedbacks." << endl;
    cout << "3) Logout." << endl;
    cout << "4) Exit." << endl;
}
void System::printCustomersNames()
{
    unsigned int index = 1;
    Customer **customer_array = this->getCostumeArray();
    for (int i = 0; i < this->getCustomerArraySize(); i++)
    {
        char name[11];
        strcpy(name, customer_array[i]->getName());
        cout << index << " " << name << endl;
        index++;
    }
}
void System::printSellersNames()
{
    unsigned int index = 1;
    Seller **sellers_array = this->getSellersArray();
    for (int i = 0; i < this->getSellersArraySize(); i++)
    {
        char name[11];
        strcpy(name, sellers_array[i]->getUserName());
        cout << index << " " << name << endl;
        index++;
    }
}
void Seller::printSellerProducts()
{
    int length = this->getStockArraySize();
    Product **products_array = this->getStock();
    Product *product = nullptr;
    for (int i = 0; i < length; i++)
    {
        cout << "Product number #" << i + 1 << " ";
        products_array[i]->printProduct();
        cout << endl;
    }
}
