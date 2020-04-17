#ifndef __EXAMPLE_IOBSERVER_H__
#define	__EXAMPLE_IOBSERVER_H__

#include <string>
//

using namespace std;

class IObserver {
public:

	virtual ~IObserver() {};
	virtual void update(const string &messageFromSubject) = 0;	// VP
};

#endif // __EXAMPLE_IOBSERVER_H__
