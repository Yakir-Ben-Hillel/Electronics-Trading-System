#ifndef __FEEDBACK_H
#define __FEEDBACK_H

class Date;
class Customer;

class FeedBack
{
public:
    enum efeedback
    {
        A = 'A',
        B,
        C,
        D,
        E
    }; //A is like 5 stars and E is like 1 star
    //constructors and distructors
    FeedBack() = default;
    FeedBack(const char *note, efeedback givenrating, Customer *customer_data, Date *curr_date);
    FeedBack(FeedBack &other);
    ~FeedBack();

    //seters and geters
    bool setNotes(const char *givenNote);
    bool setRating(efeedback givenrating);
    bool setCustomerName(const Customer *other_customer);
    bool setDateOfFeedBack(Date *date);

    const char *getNotes() const;
    efeedback getrating() const;
    Customer *getCustomerName() const;
    Date *getDate();

private:
    Customer *customer;
    char *notes;
    FeedBack::efeedback rating;
    Date *date_of_feedback; //need to do seters and geters and update the constructor
};

#endif