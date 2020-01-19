#include "../../include/system.h"

FeedBack::FeedBack(const string &note,const Customer &customer_data,const Date &curr_date) noexcept(false)
:customer(customer_data),date_of_feedback(curr_date)
{
    if (note.empty())
        throw FeedBackException(curr_date, note); //if date has an exception the function that called this constractor will catch it.
    setNotes(note);
}
FeedBack::FeedBack(const FeedBack &other)
    : notes(other.notes), date_of_feedback(other.date_of_feedback), customer(other.customer)
{
}
FeedBack::FeedBack(FeedBack &&other)
    : notes(other.notes), date_of_feedback(other.date_of_feedback), customer(other.customer)
{
}
FeedBack::~FeedBack()
{
}
bool FeedBack::setNotes(const string &givenNote)
{
    this->notes = givenNote;
    return true;
}
const string &FeedBack::getNotes() const
{
    return notes;
}
const Customer &FeedBack::getCustomer() const
{
    return customer;
}
const Date &FeedBack::getDate() const
{
    return date_of_feedback;
}
ostream &operator<<(ostream &out, const FeedBack &feedback)
{

    out << "the customer who gave you the feedback: " << feedback.customer.getName() << endl;
    out << "the date of the feedback is: " << feedback.date_of_feedback << endl;
    out << "the notes are: " << feedback.notes << endl;
    return out;
}
