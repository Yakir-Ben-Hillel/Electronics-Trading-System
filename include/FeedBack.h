#ifndef __FEEDBACK_H
#define __FEEDBACK_H

class Date;
class Customer;

class FeedBack
{
public:
    //constructors and distructors
    FeedBack(const string &note,const Customer &customer_data,const Date &curr_date) noexcept(false);
    FeedBack(const FeedBack &other);
    FeedBack(FeedBack &&other);
    ~FeedBack() {this->customer=nullptr;}

    //seters and geters
    bool setNotes(const string &givenNote);
    const string &getNotes() const;
    const Customer &getCustomer() const;
    const Date &getDate() const;
    const FeedBack& operator=(const FeedBack& other);
    friend ostream &operator<<(ostream &out, const FeedBack &feedback);

private:
    const Customer *customer;
    string notes;
    const Date *date_of_feedback;
};

#endif