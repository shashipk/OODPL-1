#ifndef __EXAMPLE_ISUBJECT_H__
#define	__EXAMPLE_ISUBJECT_H__

#include "IObserver.h"
//

class ISubject {
public:

	virtual ~ISubject() {};
	virtual void attach(IObserver *observer)	= 0;	// VP
	virtual void detach(IObserver *observer)	= 0;	// VP
	virtual void notify()						= 0;	// VP
};

#endif // __EXAMPLE_ISUBJECT_H__
