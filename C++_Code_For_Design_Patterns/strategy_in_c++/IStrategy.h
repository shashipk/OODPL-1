#ifndef __EXAMPLE_ISTRATEGY_H__
#define __EXAMPLE_ISTRATEGY_H__


class IStrategy {
public:
	enum ENUM_ACCOUNT { ACCOUNT_PREMIUM, ACCOUNT_NORMAL };
public:
	virtual ~IStrategy() {};
	virtual void displayComponents() = 0;
	virtual void setComponent1(bool b) = 0;
	virtual void setComponent2(bool b) = 0;
	virtual void setComponent3(bool b) = 0;
	virtual const bool getComponent1() const = 0;
	virtual const bool getComponent2() const = 0;
	virtual const bool getComponent3() const = 0;

protected:
	virtual void displayComponent1() = 0;
	virtual void displayComponent2() = 0;
	virtual void displayComponent3() = 0;
	bool _visibilityComponent1;
	bool _visibilityComponent2;
	bool _visibilityComponent3;
};

#endif // __EXAMPLE_ISTRATEGY_H__
