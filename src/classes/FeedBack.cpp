#include "../../include/system.h"

FeedBack::FeedBack(char *note, Customer *customer_data, Date *curr_date)
    : customer(customer_data), date_of_feedback(curr_date)
{
    setNotes(note);
}
FeedBack::FeedBack(const FeedBack &other)
{
    setNotes(other.notes);
    setCustomer(other.customer);
    setDateOfFeedBack(other.date_of_feedback);
}
FeedBack::FeedBack(FeedBack &&other)
{
    this->customer = other.customer;
    this->date_of_feedback = other.date_of_feedback;
    this->notes = other.notes;

    other.notes = nullptr;
    other.date_of_feedback = nullptr;
    other.customer = nullptr;
}
FeedBack::~FeedBack()
{
    date_of_feedback = nullptr;
    delete[] notes;
    customer = nullptr;
}

bool FeedBack::setNotes(const char *givenNote)
{
    notes = new char[strlen(givenNote) + 1];
    strcpy(notes, givenNote);
    return true;
}
bool FeedBack::setCustomer(const Customer *other_customer)
{
    customer = other_customer;
    return true;
}
bool FeedBack::setDateOfFeedBack(const Date *date)
{
    date_of_feedback = date;
    return true;
}
const char *FeedBack::getNotes() const
{
    return notes;
}
const Customer *FeedBack::getCustomer() const
{
    return customer;
}
const Date *FeedBack::getDate()
{
    return date_of_feedback;
}
ostream &operator<<(ostream &out, const FeedBack &feedback)
{
    if (typeid(out) == typeid(ofstream))
    {
        out << *feedback.customer << " " << feedback.date_of_feedback << " "
            << feedback.notes;
    }
    else
    {
        out << "the customer who gave you the feedback: " << feedback.customer->getName() << endl;
        out << "the date of the feedback is: " << feedback.date_of_feedback->getDay() << "/" << feedback.date_of_feedback->getMonth() << "/" << feedback.date_of_feedback->getYear() << endl;
        out << "the notes are: " << feedback.notes << endl;
    }
    return out;
}
istream &operator>>(istream &in, FeedBack &feedback)
{
    Customer *customerTemp = new Customer(*feedback.customer);
    Date *dateTemp = new Date(*feedback.date_of_feedback);
    in >> *customerTemp >> *dateTemp >> feedback.notes;
    return in;
}