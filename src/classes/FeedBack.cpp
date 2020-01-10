#include "../../include/system.h"

FeedBack::FeedBack(char *note,const Customer *customer_data,const Date& curr_date) noexcept(false)
    : customer(customer_data), date_of_feedback(curr_date)
{
    if (strcmp(note, "") == 0)
        throw FeedBackException(curr_date, note); //if date has an exception the function that called this constractor will catch it.
    setNotes(note);
}
FeedBack::FeedBack(const FeedBack &other):date_of_feedback(other.date_of_feedback)
{
    setNotes(other.notes);
    setCustomer(other.customer);
}
FeedBack::FeedBack(FeedBack &&other):date_of_feedback(other.date_of_feedback)
{
    this->customer = other.customer;
    this->notes = other.notes;

    other.notes = nullptr;
    other.customer = nullptr;
}
FeedBack::~FeedBack()
{
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
const char *FeedBack::getNotes() const
{
    return notes;
}
const Customer *FeedBack::getCustomer() const
{
    return customer;
}
const Date& FeedBack::getDate() const
{
    return date_of_feedback;
}
ostream &operator<<(ostream &out, const FeedBack &feedback)
{

    out << "the customer who gave you the feedback: " << feedback.customer->getName() << endl;
    out << "the date of the feedback is: " << feedback.date_of_feedback << endl;
    out << "the notes are: " << feedback.notes << endl;
    return out;
}