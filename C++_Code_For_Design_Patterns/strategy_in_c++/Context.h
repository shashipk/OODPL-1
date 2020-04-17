#ifndef __EXAMPLE_CONTEXT_H__
#define __EXAMPLE_CONTEXT_H__


//#include <memory>
#include "IStrategy.h"

class Context {
public:
	Context();
	~Context();

	void setStrategy(const std::shared_ptr<IStrategy> &strategy, IStrategy::ENUM_ACCOUNT account);
	void dealWithStrategy();

private:
	IStrategy::ENUM_ACCOUNT _account;
	std::shared_ptr<IStrategy> _strategy;
};

#endif // __EXAMPLE_CONTEXT_H__
