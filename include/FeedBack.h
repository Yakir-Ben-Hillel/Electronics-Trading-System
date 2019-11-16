#ifndef __FEEDBACK_H
#define __FEEDBACK_H
#include "system.h"

class Date;

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
    FeedBack(const char *note, efeedback givenrating, const char *customer_name);
    FeedBack(FeedBack &other);
    ~FeedBack();

    //seters and geters
    bool setNotes(const char *givenNote);
    bool setRating(efeedback givenrating);
    bool setCustomerName(const char *name);

    const char *getNotes() const;
    efeedback getrating() const;
    const char *getCustomerName() const;

private:
    char *name_of_customer;
    char *notes;
    efeedback rating;
    Date *date_of_feedback;//need to do seters and geters and update the constructor
};

#endif