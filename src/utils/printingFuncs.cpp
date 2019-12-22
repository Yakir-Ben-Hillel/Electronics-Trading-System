#include "../../include/system.h"
void System::printOpening() const
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
void System::printOptionsAsGuest() const
{
    cout << "1) Login." << endl;
    cout << "2) SignUp." << endl;
    cout << "3) Print all Customers names." << endl;
    cout << "4) Print all Sellers names." << endl;
    cout << "5) Exit." << endl;
    cout << "Please insert the number of your chosen option: ";
}

void System::printOptionsAsCustomer() const
{
    cout << "1) Add Product to your Wishlist." << endl;
    cout << "2) Add Feedback to a Seller." << endl;
    cout << "3) Make an Order." << endl;
    cout << "4) Print all Sellers names." << endl;
    cout << "5) Search for a Product" << endl;
    cout << "6) Logout." << endl;
    cout << "7) Exit" << endl;
}
void System::printOptionsAsSeller() const
{
    cout << "1) Add a Product." << endl;
    cout << "2) View your Feedbacks." << endl;
    cout << "3) Logout." << endl;
    cout << "4) Exit." << endl;
}
void System::printCustomersNames() const
{
    unsigned int counter = 1;
    Customer *customerTemp = nullptr;
    for (int i = 0; i < this->users_array_logical_size; i++)
    {
        customerTemp = dynamic_cast<Customer *>(this->users_array[i]);
        if (customerTemp)
        {
            cout << counter << ") " << customerTemp->getName() << endl;
            counter++;
        }
    }
    cout << endl;
}
void System::printSellersNames() const
{
    unsigned int counter = 1;
    Seller *sellerTemp = nullptr;
    for (int i = 0; i < users_array_logical_size; i++)
    {
        sellerTemp = dynamic_cast<Seller *>(this->users_array[i]);
        if (sellerTemp)
        {
            cout << counter << ") " << sellerTemp->getName() << endl;
            counter++;
        }
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
    Seller *sellerTemp = nullptr;
    for (int i = 0; i < users_array_logical_size; i++)
    {
        sellerTemp = dynamic_cast<Seller *>(this->users_array[i]);
        if (sellerTemp)
        {
            if (customer->didCustomerOrderedFromSeller(sellerTemp) == true)
            {
                counter++;
                cout << counter << ") " << sellerTemp->getUserName() << endl;
            }
        }
    }
}
