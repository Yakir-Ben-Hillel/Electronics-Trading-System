#include "../include/FeedBack.h"
#include "../include/Date.h"
#include "../include/customer.h"
#include <iostream>
#include <string.h>
using namespace std;


FeedBack::FeedBack(const char *note, efeedback givenrating, Customer *customer_data, Date *curr_date)
{
    setNotes(note);
    setRating(givenrating);
    setCustomerName(customer);
    setDateOfFeedBack(curr_date);
}
FeedBack::FeedBack(FeedBack &other)
{
    setNotes(other.notes);
    setRating(other.rating);
    setCustomerName(other.customer);
    setDateOfFeedBack(other.date_of_feedback);
}
FeedBack::~FeedBack()
{
    delete date_of_feedback;
    delete[] notes;
    delete customer;
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
bool FeedBack::setCustomerName(const Customer *other_customer)
{
    *customer=Customer(*other_customer);
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
Customer *FeedBack::getCustomerName() const
{
    return customer;
}
Date *FeedBack::getDate()
{
    return date_of_feedback;
}