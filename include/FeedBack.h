#ifndef __FEEDBACK_H
#define __FEEDBACK_H
#include "./include/system.h"

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
    FeedBack()=default;
    FeedBack(const char* note,efeedback givenrating);
    FeedBack(FeedBack& other);
    ~FeedBack();

    //seters and geters
    bool setNotes(const char* givenNote);
    bool setRating(efeedback givenrating);

    const char* getNotes() const;
    efeedback getrating() const;
private:
char* notes;
efeedback rating;
};

#endif