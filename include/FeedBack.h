#ifndef __FEEDBACK_H
#define __FEEDBACK_H

class Date;
class Customer;

class FeedBack
{
public:
    //constructors and distructors
    FeedBack() = default;
    FeedBack(char *note, Customer *customer_data, Date *curr_date);
    FeedBack(const FeedBack &other);
    FeedBack(FeedBack &&other);
    ~FeedBack();

    //seters and geters
    bool setNotes(const char *givenNote);
    bool setCustomer(const Customer *other_customer);
    bool setDateOfFeedBack(const Date *date);

    const char *getNotes() const;
    const Customer *getCustomer() const;
    const Date *getDate();
    friend ostream& operator<<(ostream& out,const FeedBack& feedback);

private:
    const Customer *customer;
    char *notes;
    const Date *date_of_feedback; 
};

#endif