#include "Observer.h"
#include <iostream>

using namespace std;

int Observer::_staticNumber = 0;

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------
Observer::Observer(Subject &subject) : _subject(subject) {
	_subject.attach(this);
	cout 	<< "Hi, I'm the Observer \""
			<< ++Observer::_staticNumber << "\"." << endl;
	_number = Observer::_staticNumber;	// increased each time a new observer is created
}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
Observer::~Observer() {
	cout << "Goodbye, I was the Observer \"" << _number << "\"." << endl;
}

//-----------------------------------------------------------------------------
// Removes the observer from the observer list.
//-----------------------------------------------------------------------------
void Observer::removeMeFromTheList() {
	_subject.detach(this);
	cout << "Observer \"" << _number << "\" removed from the list." << endl;
}

//-----------------------------------------------------------------------------
// Retrieves the new message from the subject.
//-----------------------------------------------------------------------------
void Observer::update(const string &messageFromSubject) {
	_messageFromSubject = messageFromSubject;
	printInfo();
}

//-----------------------------------------------------------------------------
// Displays a message to alert that a new message has arrived.
//-----------------------------------------------------------------------------
void Observer::printInfo() {
	cout	<< "Observer \"" << Observer::_number
			<< "\": a new message is available --> "
			<< _messageFromSubject << endl;
}
