
/*
Understanding the pattern:
We will understand the pattern using an example. In the example:

1. We have a factory that produces a menu and a button
2. The products (menu and button) is platform dependant that is on Windows or Linux
3. A user (Client) will use the products
4. There are two options at this point:

The user (Client) has take care to identify the platform the product is supported and use accordingly to avoid any unexpected errors.
Note: This is not a good design as it increases the workload of the client and requires lot of error checking codes

The other option is to handle the error checking and give the user to product required directly by doing all internal checking within the factory and product interface
Note: This is a good approach and cleans the code. This is achieved through Abstract Factory Pattern

-------------------------------------------------------
We will understand this by going through 2 codes:
-------------------------------------------------------
1. one code is implemented using the first option without abstract factory pattern
2. second code is implemented using abstract factory pattern

-------------------------------------------------------
Code before using Abstract factory pattern
There are 4 components:

LINUX is defined using C++ preprocessing directive
Widget class represents the parent class for the products
We have 4 different product classes: LinuxButton, LinuxMenu, WindowsMenu and WindowsButton
We have a client class which checks if LINUX is defined, it calls the Linux product classes or else it calls the Windows product classes
Note: the client is handling if it is for Linux or Windows which makes the client code vulnerable provided something is missed.

The client creates "product" objects directly, and must embed all possible platform permutations in nasty looking code.

Go through this C++ code carefully:

*/
#include <iostream>
#define LINUX

using namespace std;

/**
 * Abstract base product.
 */
class Widget
{
 public:
  virtual void draw() = 0;
};

/**
 * Concrete product family 1.
 */
class LinuxButton : public Widget
{
 public:
  void draw() { cout << "LinuxButton\n"; }
};
class LinuxMenu : public Widget
{
 public:
  void draw() { cout << "LinuxMenu\n"; }
};

/**
 * Concrete product family 2.
 */
class WindowsButton : public Widget
{
 public:
  void draw() { cout << "WindowsButton\n"; }
};
class WindowsMenu : public Widget
{
 public:
  void draw() { cout << "WindowsMenu\n"; }
};

/**
 * Here's a client, which uses concrete products directly.
 * It's code filled up with nasty switch statements
 * which check the product type before its use.
 */
class Client
{
 public:
  void draw()
 {
#ifdef LINUX
    Widget *w = new LinuxButton;
#else // WINDOWS
    Widget *w = new WindowsButton;
#endif
    w->draw();
    display_window_one();
    display_window_two();
  }

  void display_window_one()
  {
#ifdef LINUX
    Widget *w[] =
    {
        new LinuxButton,
        new LinuxMenu
    };
#else // WINDOWS
    Widget *w[] =
    {
        new WindowsButton,
        new WindowsMenu
    };
#endif
    w[0]->draw();
    w[1]->draw();
  }

  void display_window_two()
  {
#ifdef LINUX
    Widget *w[] =
    {
        new LinuxMenu,
        new LinuxButton
    };
#else // WINDOWS
    Widget *w[] =
    {
        new WindowsMenu,
        new WindowsButton
    };
#endif
    w[0]->draw();
    w[1]->draw();
  }
};

int main()
{
  Client *c = new Client();
  c->draw();
}
/*
-------------------------------------------------------
Code after using Abstract factory pattern
-------------------------------------------------------
There are 5 components:

LINUX is defined using C++ preprocessing directive
Widget class represents the parent class for the products
We have 4 different product classes: LinuxButton, LinuxMenu, WindowsMenu and WindowsButton
There is an additional Factory class which handles the error checking and creates the platform specific product (Widget) depending on the platform defined.
We have a client class using the Factory class and has to do no checking
The issue has been resolved. Note: the difference in the client code is significant.

The client receives a platform-specific factory object, which encapsulates use of "new" operator.

*/

#include <iostream>
#define LINUX

using namespace std;

/**
 * Abstract base product. It should define an interface
 * which will be common to all products. Clients will
 * work with products through this interface, so it
 * should be sufficient to use all products.
 */
class Widget
{
 public:
  virtual void draw() = 0;
};

/**
 * Concrete product family 1.
 */
class LinuxButton : public Widget
{
 public:
  void draw() { cout << "LinuxButton\n"; }
};
class LinuxMenu : public Widget
{
 public:
  void draw() { cout << "LinuxMenu\n"; }
};

/**
 * Concrete product family 2.
 */
class WindowsButton : public Widget
{
 public:
  void draw() { cout << "WindowsButton\n"; }
};
class WindowsMenu : public Widget
{
 public:
  void draw() { cout << "WindowsMenu\n"; }
};

/**
 * Abstract factory defines methods to create all
 * related products.
 */
class Factory
{
 public:
  virtual Widget *create_button() = 0;
  virtual Widget *create_menu() = 0;
};

/**
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
 */
class LinuxFactory : public Factory
{
 public:
  Widget *create_button()
  {
    return new LinuxButton;
  }
  Widget *create_menu()
  {
    return new LinuxMenu;
  }
};

/**
 * Concrete factory creates concrete products, but
 * returns them as abstract.
 */
class WindowsFactory : public Factory
{
 public:
  Widget *create_button()
  {
    return new WindowsButton;
  }
  Widget *create_menu()
  {
    return new WindowsMenu;
  }
};

/**
 * Client receives a factory object from its creator.
 *
 * All clients work with factories through abstract
 * interface. They don't know concrete classes of
 * factories. Because of this, you can interchange
 * concrete factories without breaking clients.
 *
 * Clients don't know the concrete classes of created
 * products either, since abstract factory methods
 * returns abstract products.
 */
class Client
{
 private:
  Factory *factory;

 public:
  Client(Factory *f)
  {
    factory = f;
  }

  void draw()
  {
    Widget *w = factory->create_button();
    w->draw();
    display_window_one();
    display_window_two();
  }

  void display_window_one()
  {
    Widget *w[] = {
        factory->create_button(),
        factory->create_menu()
    };
    w[0]->draw();
    w[1]->draw();
  }

  void display_window_two()
  {
    Widget *w[] =
    {
        factory->create_menu(),
        factory->create_button()
    };
    w[0]->draw();
    w[1]->draw();
  }
};

/**
 * Now the nasty switch statement is needed only once to
 * pick and create a proper factory. Usually that's
 * happening somewhere in program initialization code.
 */
int main()
{
  Factory *factory;
#ifdef LINUX
  factory = new LinuxFactory;
#else // WINDOWS
  factory = new WindowsFactory;
#endif

  Client *c = new Client(factory);
  c->draw();
}
