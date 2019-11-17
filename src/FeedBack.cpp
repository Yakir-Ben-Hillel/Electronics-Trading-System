#include "FeedBack.h"

FeedBack::FeedBack(const char *note, efeedback givenrating, const char *customer_name, Date *curr_date)
{
    setNotes(note);
    setRating(givenrating);
    setCustomerName(customer_name);
    setDateOfFeedBack(curr_date);
}
FeedBack::FeedBack(FeedBack &other)
{
    setNotes(other.notes);
    setRating(other.rating);
    setCustomerName(other.name_of_customer);
    setDateOfFeedBack(other.date_of_feedback);
}
FeedBack::~FeedBack()
{
    delete date_of_feedback;
    delete[] notes;
    delete[] name_of_customer;
}

bool FeedBack::setNotes(const char *givenNote)
{
    notes = new char[strlen(givenNote) + 1];
    strcpy(notes, givenNote);
    return true;
}
bool FeedBack::setRating(FeedBack::efeedback givenrating)
{
    if (givenrating != A || givenrating != B || givenrating != C || givenrating != D || givenrating != E)
    {
        cout << "you can only pick rating from A to E" << endl;
        return false;
    }
    rating = givenrating;
    return true;
}
bool FeedBack::setCustomerName(const char *name)
{
    name_of_customer = new char[strlen(name) + 1];
    strcpy(name_of_customer, name);
    return true;
}
bool FeedBack::setDateOfFeedBack(Date *date)
{
    date_of_feedback=new Date(*date);
    return true;
}
const char *FeedBack::getNotes() const
{
    return notes;
}
FeedBack::efeedback FeedBack::getrating() const
{
    return rating;
}
const char *FeedBack::getCustomerName() const
{
    return name_of_customer;
}
Date *FeedBack::getDate()
{
    return date_of_feedback;
}