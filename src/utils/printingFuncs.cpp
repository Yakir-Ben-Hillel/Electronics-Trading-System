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
    cout << "5) Print all users that are Customers and Sellers." << endl;
    cout << "6) Compare two Customers by their Wishlist price." << endl;
    cout << "7) Exit." << endl;
    cout << "Please insert the number of your chosen option: ";
}

void System::printOptionsAsCustomer() const
{
    cout << "1) Add Product to your Wishlist." << endl;
    cout << "2) Add Feedback to a Seller." << endl;
    cout << "3) Make an Order." << endl;
    cout << "4) Print all Sellers names." << endl;
    cout << "5) Search for a Product." << endl;
    cout << "6) Print your user's info." << endl;
    cout << "7) change PassWord." << endl;
    cout << "8) Logout." << endl;
    cout << "9) Exit." << endl;
}
void System::printOptionsAsSeller() const
{
    cout << "1) Add a Product." << endl;
    cout << "2) View your Feedbacks." << endl;
    cout << "3) Print your user's info." << endl;
    cout << "4) change PassWord." << endl;
    cout << "5) Logout." << endl;
    cout << "6) Exit." << endl;
}
void System::printOptionAsCAS() const
{
    cout << "1) Add Product to your Wishlist." << endl;
    cout << "2) Add Feedback to a Seller." << endl;
    cout << "3) Make an Order." << endl;
    cout << "4) Print all Sellers names." << endl;
    cout << "5) Add a Feedback to a Seller." << endl;
    cout << "6) Search for a Product" << endl;
    cout << "7) Add a Product." << endl;
    cout << "8) View your Feedbacks." << endl;
    cout << "9) Print your user's info." << endl;
    cout << "10) change PassWord." << endl;
    cout << "11) Logout." << endl;
    cout << "12) Exit." << endl;
}
void System::printCustomersNames() const
{
    unsigned int temp_counter = 0;
    Customer *customerTemp = nullptr;
    vector<User *>::const_iterator itr = this->users_array.begin();
    vector<User *>::const_iterator itrEnd = this->users_array.end();

    for (; itr != itrEnd; ++itr)
    {
        customerTemp = dynamic_cast<Customer *>(*itr);
        if (customerTemp)
        {
            cout << temp_counter + 1 << ") " << customerTemp->getName() << endl;
            temp_counter++;
        }
    }
    cout << endl;
}
void System::printSellersNames() const
{
    unsigned int counter = 1;
    Seller *sellerTemp = nullptr;
    vector<User *>::const_iterator itr = this->users_array.begin();
    vector<User *>::const_iterator itrEnd = this->users_array.end();

    for (; itr != itrEnd; ++itr)
    {
        sellerTemp = dynamic_cast<Seller *>(*itr);
        if (sellerTemp)
        {
            cout << counter << ") " << sellerTemp->getName() << endl;
            counter++;
        }
    }
    cout << endl;
}
void System::printCASNames() const
{
    unsigned int counter = 0;
    CAS *temp = nullptr;
    vector<User *>::const_iterator itr = this->users_array.begin();
    vector<User *>::const_iterator itrEnd = this->users_array.end();

    for (; itr != itrEnd; ++itr)
    {
        temp = dynamic_cast<CAS *>(*itr);
        if (temp)
        {
            cout << counter + 1 << ") " << temp->getName() << endl;
            ++counter;
        }
    }
    cout << endl;
}
void Seller::printSellerProducts()
{
    vector<Product *> products_array = this->getStock();
    vector<Product *>::const_iterator itr = products_array.begin();
    vector<Product *>::const_iterator itrEnd = products_array.end();
    Product *product = nullptr;
    for (int i = 1; itr != itrEnd; ++itr, i++)
    {
        cout << "Product number #" << i << " ";
        cout << *(*itr);
        cout << endl;
    }
}
void System::printAllAvailableSellersToGiveFeedbacks(Customer &customer)
{
    unsigned int counter = 0;
    Seller *sellerTemp = nullptr;
    vector<User *>::const_iterator itr = this->users_array.begin();
    vector<User *>::const_iterator itrEnd = this->users_array.end();

    for (; itr != itrEnd; ++itr)
    {
        sellerTemp = dynamic_cast<Seller *>(*itr);
        if (sellerTemp)
        {
            if (customer.didCustomerOrderedFromSeller(*sellerTemp) == true)
            {
                counter++;
                cout << counter << ") " << sellerTemp->getName() << endl;
            }
        }
    }
}
void System::showProductsWithTheSameName(const string &name)
{
    Seller *seller_temp = nullptr;
    bool isFound = false;
    vector<User *>::const_iterator itr = this->users_array.begin();
    vector<User *>::const_iterator itrEnd = this->users_array.end();
    for (; itr != itrEnd; ++itr)
    {
        seller_temp = dynamic_cast<Seller *>(*itr);
        if (seller_temp)
        {
            vector<Product *> stock = seller_temp->getStock();
            vector<Product *>::const_iterator itrP = stock.begin();
            vector<Product *>::const_iterator itrPEnd = stock.end();

            for (; itrP != itrPEnd; ++itrP)
            {
                if (isSubstring(name, (*itrP)->getName()))
                {
                    isFound = true;
                    cout << *(*itrP);
                    cout << endl;
                }
            }
            isFound ? cout << "The Products you have searched for ,is shown to you above: " << endl : cout << "No similar Products as been found." << endl;
        }
    }
}
