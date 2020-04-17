#include <memory>
#include <iostream>
#include "IStrategy.h"
#include "Strategy1.h"
#include "Strategy2.h"
#include "Context.h"


//-----------------------------------------------------------------------------
// main
//-----------------------------------------------------------------------------
int main()
{
    Context context;
    auto strategy1 = std::make_shared<Strategy1>();  // strategy 1
    auto strategy2 = std::make_shared<Strategy2>();  // strategy 2

    //
	std::cout << std::endl << "Strategy 1";
    context.setStrategy(strategy1, IStrategy::ACCOUNT_NORMAL);
	context.dealWithStrategy();
	context.setStrategy(strategy1, IStrategy::ACCOUNT_PREMIUM);
	context.dealWithStrategy();
    //
	std::cout << std::endl << "Strategy 2";
    context.setStrategy(strategy2, IStrategy::ACCOUNT_NORMAL);
	context.dealWithStrategy();
	context.setStrategy(strategy2, IStrategy::ACCOUNT_PREMIUM);
	context.dealWithStrategy();
}
