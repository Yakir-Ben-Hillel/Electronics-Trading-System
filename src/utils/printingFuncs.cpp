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
    if (this->getCustomerArraySize() == 0)
        cout << "there are no customers in the store" << endl;
    else
        cout << "the customers are: " << endl;
    for (int i = 0; i < this->getCustomerArraySize(); i++)
    {
        char name[11];
        strcpy(name, customer_array[i]->getName());
        cout << index << ") " << name << endl;
        index++;
    }
    cout << endl;
}
void System::printSellersNames()
{
    unsigned int index = 1;
    Seller **sellers_array = this->getSellersArray();
    if (this->getSellersArraySize() == 0)
    {
        cout << "There are no sellers available in the store now,please try again later." << endl;
    }
    else
        cout << "the sellers are: " << endl;
    for (int i = 0; i < this->getSellersArraySize(); i++)
    {
        char name[11];
        strcpy(name, sellers_array[i]->getUserName());
        cout << index << ") " << name << endl;
        index++;
    }
    cout << endl;
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
void System::printAllAvailableSellersToGiveFeedbacks(Customer *customer)
{
    unsigned int counter = 0;
    unsigned int length = this->seller_array_logical_size;
    for (int i = 0; i < length; i++)
    {
        if (customer->didCustomerOrderedFromSeller(this->s_sellers_array[i]) == true)
        {
            counter++;
            cout << counter << ") " << this->s_sellers_array[i]->getUserName() << endl;
        }
    }
}
