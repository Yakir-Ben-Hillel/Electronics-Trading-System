#include "./include/FeedBack.h"

FeedBack::FeedBack(const char *note, efeedback givenrating)
{
    setNotes(note);
    setRating(givenrating);
}
FeedBack::FeedBack(FeedBack &other)
{
    setNotes(other.notes);
    setRating(other.rating);
}
FeedBack::~FeedBack()
{
    delete[] notes;
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
const char *FeedBack::getNotes() const
{
    return notes;
}
FeedBack::efeedback FeedBack::getrating() const
{
    return rating;
}