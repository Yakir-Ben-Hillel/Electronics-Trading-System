#include "../../include/system.h"

/*
all the constractors and distractors of the exceptions classes
the function show on each class checks what input is wrong and send to the console a suitable message 
to the current problem.
also,in this file has the implemantion of the function terminate in case of unknown problem.
*/

ProductException::ProductException(const char *name, float price) : price(price)
{
    this->p_name = strdup(name);
}
ProductException::~ProductException()
{
    delete[] p_name;
}
void ProductException::show() const
{
    if (price < 0)
        cout << "price cannot be negative!" << endl;
    if (strcmp(p_name, "") == 0 || strlen(p_name) > 21)
        cout << "Error, product name cannot be blank!" << endl;
}

void DateException::show() const
{
    if (day <= 0 || day > 31)
        cout << "Error, day must be in the range of 1-31" << endl;
    if (month <= 0 || month > 12)
        cout << "Error, month must be in the range of 1-12" << endl;
    //year can be negative or positive!
    return;
}
DateException::DateException(int day, int month, int year) : day(day), month(month), year(year)
{
}

FeedBackException::FeedBackException(Date date, char *note) : date(date)
{
    this->note = strdup(note);
}
void FeedBackException::show() const
{
    if (strcmp(note, "") == 0 || strlen(note) > 256)
        cout << "Error, feedback must contain at least one letter! " << endl;
    DateException e((int)date.getDay(), (int)date.getMonth(), (int)date.getYear());
    e.show();
}
FeedBackException::~FeedBackException()
{
    delete[] note;
}

AddressException::AddressException(const Address &other)
{
    address = &other;
}
AddressException::~AddressException()
{
    this->address = nullptr;
}
void AddressException::show() const
{
    if (address->getApartmentNumber() <= 0)
        cout << "Error, apartment number is wrong!" << endl;
    if (strcmp(address->getCityName(), "") == 0)
        cout << "Error, city name cannot be blank!" << endl;
    if (strcmp(address->getStreetName(), "") == 0)
        cout << "Error, street name cannot be blank!" << endl;
    return;
}

UserException::UserException(const char *name, const char *password, const Address &address)
{
    this->name = strdup(name);
    this->password = strdup(password);
    this->address = &address;
}
UserException::~UserException()
{
    delete[] name;
    delete[] password;
    this->address = nullptr;
}
void UserException::show() const
{
    if (strcmp(name, "") == 0 || strlen(name) > 11)
        cout << "Error chosen name cannot be blank!" << endl;
    if (strcmp(password, "") == 0 || strlen(password) > 11)
        cout << "Error chosen password is wrong!" << endl;
    AddressException Ae(*address);
    Ae.show();
}
//our terminate function in case of unknown problem
void Terminate()
{
    cout << "Something went wrong, please call support for further information!" << endl;
}