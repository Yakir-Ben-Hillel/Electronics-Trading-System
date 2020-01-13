#include "../../include/system.h"

/*
all the constractors and distractors of the exceptions classes
the function show on each class checks what input is wrong and send to the console a suitable message 
to the current problem.
also,in this file has the implemantion of the function terminate in case of unknown problem.
*/

ProductException::ProductException(const string& name, float price) 
: price(price),p_name(name)
{
}
ProductException::~ProductException()
{
}
void ProductException::show() const
{
    if (price < 0)
        cout << "price cannot be negative!" << endl;
    if (p_name.compare(" ") == 0 || p_name.length() > 21)
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

FeedBackException::FeedBackException(const Date& date,const string& note) 
: date(date),note(note)
{
}
void FeedBackException::show() const
{
    if (note.compare(" ") == 0 || note.length() > 256)
        cout << "Error, feedback must contain at least one letter! " << endl;
    DateException e((int)date.getDay(), (int)date.getMonth(), (int)date.getYear());
    e.show();
}
FeedBackException::~FeedBackException()
{
}
AddressException::AddressException(unsigned int apartmentNumber, const string& streetName, const string& cityName) 
: apartmentNumber(apartmentNumber),streetName(streetName),cityName(cityName)
{
}
AddressException::~AddressException()
{
}
void AddressException::show() const
{
    if (apartmentNumber <= 0)
        cout << "Error, apartment number is wrong!" << endl;
    if (cityName.compare(" ") == 0)
        cout << "Error, city name cannot be blank!" << endl;
    if (streetName.compare(" ") == 0)
        cout << "Error, street name cannot be blank!" << endl;
    return;
}

UserException::UserException(const string& name, const string& password, const Address &address)
:address(address),name(name),password(password)
{
}
UserException::~UserException()
{
}
void UserException::show() const
{
    if (name.compare(" ") == 0 || name.length() > 11)
        cout << "Error chosen name cannot be blank!" << endl;
    if (password.compare(" ") == 0 || password.length() > 11)
        cout << "Error chosen password is wrong!" << endl;
    AddressException Ae(address.getApartmentNumber(),address.getStreetName(),address.getCityName());
    Ae.show();
}
//our terminate function in case of unknown problem
void Terminate()
{
    cout << "Something went wrong, please call support for further information!" << endl;
}