#include "Observer.h"
#include "Subject.h"

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------
int main()
{
    Subject *subject 	= new Subject();
    Observer *observer1 = new Observer(*subject);				// new observer
    Observer *observer2 = new Observer(*subject);				// new observer
    Observer *observer3 = new Observer(*subject);				// new observer
    Observer *observer4;
    Observer *observer5;

    subject->createMessage("Hello World! :D");					// new message
    observer3->removeMeFromTheList();							// removing an observer
    subject->createMessage("The weather is hot today! :p");		// new message
    observer4 = new Observer(*subject);							// new observer
    observer2->removeMeFromTheList();							// removing an observer
    observer5 = new Observer(*subject);							// new observer
    subject->createMessage("My new car is great! ;)");			// new message
    observer5->removeMeFromTheList();							// removing an observer
    observer4->removeMeFromTheList();							// removing an observer
    observer1->removeMeFromTheList();							// removing an observer

    // deleting
    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

    return 0;
}
