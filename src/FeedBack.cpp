#include "../include/includes.h"

FeedBack::FeedBack(const char *note, Customer *customer_data, Date *curr_date)
{
    setNotes(note);
    setCustomer(customer);
    setDateOfFeedBack(curr_date);
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
bool FeedBack::setCustomer(const Customer *other_customer)
{
    customer = new Customer(*other_customer);
    return true;
}
bool FeedBack::setDateOfFeedBack(Date *date)
{
    date_of_feedback = new Date(*date);
    return true;
}
const char *FeedBack::getNotes() const
{
    return notes;
}
Customer *FeedBack::getCustomer() const
{
    return customer;
}
Date *FeedBack::getDate()
{
    return date_of_feedback;
}