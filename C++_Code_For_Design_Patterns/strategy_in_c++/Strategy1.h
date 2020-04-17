#ifndef __EXAMPLE_STRATEGY1_H__
#define __EXAMPLE_STRATEGY1_H__


#include "IStrategy.h"

class Strategy1 : public IStrategy {
public:
	Strategy1();
	~Strategy1();

	void displayComponents() override;
	void setComponent1(bool b) override;
	void setComponent2(bool b) override;
	void setComponent3(bool b) override;
	const bool getComponent1() const override;
	const bool getComponent2() const override;
	const bool getComponent3() const override;

private:
	void displayComponent1() override;
	void displayComponent2() override;
	void displayComponent3() override;
};

#endif // __EXAMPLE_STRATEGY1_H__
