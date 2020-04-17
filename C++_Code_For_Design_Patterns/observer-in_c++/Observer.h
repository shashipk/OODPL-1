#ifndef __EXAMPLE_OBSERVER_H__
#define	__EXAMPLE_OBSERVER_H__

#include "IObserver.h"
#include "Subject.h"

class Observer : public IObserver
{
public:
	Observer(Subject &subject);
	virtual ~Observer();

	void update(const string &messageFromSubject);
	void removeMeFromTheList();
	void printInfo();

private:
	string		_messageFromSubject;
	Subject&	_subject;
	static int	_staticNumber;
	int			_number;
};

#endif // __EXAMPLE_OBSERVER_H__
