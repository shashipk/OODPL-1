#ifndef __EXAMPLE_SUBJECT_H__
#define	__EXAMPLE_SUBJECT_H__

#include <list>
#include "ISubject.h"

class Subject : public ISubject
{
public:
	Subject();
	virtual ~Subject();

	void attach(IObserver *observer);
	void detach(IObserver *observer);
	void notify();

	void createMessage(string message = "Empty");
	void howManyObserver();

private:
	list<IObserver *> _listObserver;
	string	_message;
};

#endif // __EXAMPLE_SUBJECT_H__
