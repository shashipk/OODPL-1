/*
------------------------------
Decorator design pattern
------------------------------
- Create a "lowest common denominator" that makes classes interchangeable
- Create a second level base class for optional functionality
- "Core" class and "Decorator" class declare an "isa" relationship
- Decorator class "has a" instance of the "lowest common denominator"
- Decorator class delegates to the "has a" object
- Create a Decorator derived class for each optional embellishment
- Decorator derived classes delegate to base class AND add extra stuff
- Client has the responsibility to compose desired configurations
*/
#include <iostream>
using namespace std;

// 1. "lowest common denominator"
class Widget
{
  public:
    virtual void draw() = 0;
};

class TextField: public Widget
{
    // 3. "Core" class & "is a"
    int width, height;
  public:
    TextField(int w, int h)
    {
        width = w;
        height = h;
    }

    /*virtual*/
    void draw()
    {
        cout << "TextField: " << width << ", " << height << '\n';
    }
};

// 2. 2nd level base class
class Decorator: public Widget  // 4. "is a" relationship
{
    Widget *wid; // 4. "has a" relationship
  public:
    Decorator(Widget *w)
    {
        wid = w;
    }

    /*virtual*/
    void draw()
    {
        wid->draw(); // 5. Delegation
    }
};

class BorderDecorator: public Decorator
{
  public:
    // 6. Optional embellishment
    BorderDecorator(Widget *w): Decorator(w){}

    /*virtual*/
    void draw()
    {
        // 7. Delegate to base class and add extra stuff
        Decorator::draw();
        cout << "   BorderDecorator" << '\n';
    }
};

class ScrollDecorator: public Decorator
{
  public:
    // 6. Optional embellishment
    ScrollDecorator(Widget *w): Decorator(w){}

    /*virtual*/
    void draw()
    {
        // 7. Delegate to base class and add extra stuff
        Decorator::draw();
        cout << "   ScrollDecorator" << '\n';
    }
};

int main()
{
  // 8. Client has the responsibility to compose desired configurations
  Widget *aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator
    (new TextField(80, 24))));
  aWidget->draw();
}
