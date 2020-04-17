#include "Subject.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------
Subject::Subject() {
}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
Subject::~Subject() {
	cout << "Goodbye, I was the Subject." << endl;
}

//-----------------------------------------------------------------------------
// Creates a new message and notifies all observers.
//-----------------------------------------------------------------------------
void Subject::createMessage(string message) {
	_message	= message;
	notify();
}

//-----------------------------------------------------------------------------
// Displays how many observers there are in the list.
//-----------------------------------------------------------------------------
void Subject::howManyObserver() {
	cout 	<< "There are "
			<< _listObserver.size()
			<< " observers in the list." << endl;
}

//-----------------------------------------------------------------------------
// Attaches a new observer in the list.
//-----------------------------------------------------------------------------
void Subject::attach(IObserver *observer) {
	_listObserver.push_back(observer);
}

//-----------------------------------------------------------------------------
// Detaches an observer from the list.
//-----------------------------------------------------------------------------
void Subject::detach(IObserver *observer) {
	_listObserver.remove(observer);
}

//-----------------------------------------------------------------------------
// Notifies all observers that a new message has arrived.
//-----------------------------------------------------------------------------
void Subject::notify() {
	list<IObserver *>::iterator iterator = _listObserver.begin();

	howManyObserver();
	while (iterator != _listObserver.end()) {
		(*iterator)->update(_message);
		++iterator;
	}
}
