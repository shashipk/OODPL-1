#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton *getInstance();

private:
	Singleton(){}
	static Singleton* instance;
};

Singleton* Singleton::instance = 0;
Singleton* Singleton::getInstance()
{
	if(!instance) {
		instance = new Singleton();
		cout << "getInstance(): First instance\n";
		return instance;
	}
	else {
		cout << "getInstance(): previous instance\n";
		return instance;
	}
}

int main()
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	return 0;
}


/*

Singleton pattern limits the instantiation of a class to one object.
 This is useful when exactly one object is needed to coordinate actions across the system. The concept is sometimes generalized to systems that operate more efficiently when only one object exists, or that restrict the instantiation to a certain number of objects (say, five). Some consider it an anti-pattern, judging that it is overused, introduces unnecessary limitations in situations where a sole instance of a class is not actually required, and introduces global state into an application.

We can modify the design of the code with the following constraints:

We do not want the singleton by copied so that there is only one instance. This can be achieved by declaring a private copy constructor and a private assignment operator.
The getInstance() method should return a reference rather than a pointer. This blocks a client from deleting the object. Also, by making destructor private, we can achieve the same effect.
The revised code looks like this:

*/

#include <iostream>

class Singleton
{
public:
	static Singleton& getInstance();

private:
	Singleton() {std::cout << "Ctor\n";};
	~Singleton() {std::cout << "Dtor\n";};
	Singleton(const Singleton&);
	const Singleton& operator=(const Singleton&);
};

Singleton& Singleton::getInstance()
{
	static Singleton instance;
	return instance;
}

int main()
{
	Singleton &s1; = Singleton::getInstance();
	Singleton &s2; = Singleton::getInstance();
	return 0;
}

/*
Thread Safe Singleton
The revised version is not thread safe because there could be a race condition during the initialization of the static Singleton, Singleton& Singleton::getInstance(). But we can make the method thread safe by adding a mutex lock:

Singleton& Singleton::getInstance()
{
        Mutex mutex;
        ScopedLock(&mutex;);  // to unlock mutex on exit
	static Singleton instance;
	return instance;
}
*/
