#include <memory>
#include <iostream>
#include "Context.h"
#include "IStrategy.h"

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------
Context::Context() {
  std::cout << __FUNCTION__ << std::endl;
}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
Context::~Context() {
  std::cout << std::endl << __FUNCTION__ << std::endl;
}

//-----------------------------------------------------------------------------
// setContext
//-----------------------------------------------------------------------------
void Context::setStrategy(const std::shared_ptr<IStrategy> &strategy, IStrategy::ENUM_ACCOUNT account) {
  _strategy = strategy;
  _account = account;
}

//-----------------------------------------------------------------------------
// displayComponents
//-----------------------------------------------------------------------------
void Context::dealWithStrategy() {
  // finds the account rights
  switch (_account)
  {
    case IStrategy::ACCOUNT_PREMIUM:
      std::cout << std::endl;
      std::cout << "=== Premium account ===" << std::endl;
      _strategy->setComponent1(true);
      _strategy->setComponent2(true);
      _strategy->setComponent3(true);
      break;

    case IStrategy::ACCOUNT_NORMAL:
      std::cout << std::endl;
      std::cout << "=== Normal account ===" << std::endl;
      _strategy->setComponent1(true);
      _strategy->setComponent2(false);
      _strategy->setComponent3(false);
      break;

    default:
      std::cout << "=== Wrong account ===" << std::endl;
      _strategy->setComponent1(false);
      _strategy->setComponent2(false);
      _strategy->setComponent3(false);
      break;
  }

  // displays corresponding components depending of user rights
  _strategy->displayComponents();
}
