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
    cout << "5) print all CAS users." << endl;
    cout << "6) Exit." << endl;
    cout << "Please insert the number of your chosen option: ";
}

void System::printOptionsAsCustomer() const
{
    cout << "1) Add Product to your Wishlist." << endl;
    cout << "2) Add Feedback to a Seller." << endl;
    cout << "3) Make an Order." << endl;
    cout << "4) Print all Sellers names." << endl;
    cout << "5) Search for a Product" << endl;
    cout << "6) compare between to customers by their sum of wish list" << endl;
    cout << "7) Logout." << endl;
    cout << "8) Exit" << endl;
}
void System::printOptionsAsSeller() const
{
    cout << "1) Add a Product." << endl;
    cout << "2) View your Feedbacks." << endl;
    cout << "3) Logout." << endl;
    cout << "4) Exit." << endl;
}
void System::printOptionAsCAS() const
{
    int x;
    bool isValid = true;
    cout << "Would you like to Enter your seller or customer zone?" << endl;
    cout << "Seller-1 Customer-2 :";
    cin >> x;
    cout << endl;
    //if the user is customer and seller he has to choose what zone he want to enter.
    do
    {
        switch (x)
        {
        case 1:
            System::printOptionsAsSeller();
            break;
        case 2:
            System::printOptionsAsCustomer();
            break;
        default:
            cout << "you enter wrong choice please try again." << endl;
            isValid = false;
            break;
        }
    } while (!isValid);
}
void System::printCustomersNames() const
{
    unsigned int temp_counter=0;
    Customer *customerTemp = nullptr;
    for (int i = 0; i < this->users_array_logical_size; i++)
    {
        customerTemp = dynamic_cast<Customer *>(this->users_array[i]);
        if (customerTemp)
        {
            cout << temp_counter+1 << ") " << customerTemp->getName() << endl;
            temp_counter++;
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
void System::printCASNames() const
{
  CAS* temp;
  for(int i=0,counter=0;i<this->users_array_logical_size;++i)
  {
      temp=dynamic_cast<CAS*>(this->users_array[i]);
      if(temp)
      {
          cout<<counter+1<<") "<<temp->getName()<<endl;
          ++counter;
      }
  }
  cout<<endl;
}
void Seller::printSellerProducts()
{
    int length = this->getStockArraySize();
    Product **products_array = this->getStock();
    Product *product = nullptr;
    for (int i = 0; i < length; i++)
    {
        cout << "Product number #" << i + 1 << " ";
        cout << products_array[i];
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
