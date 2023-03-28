https://stackoverflow.com/questions/11067975/overriding-non-virtual-methods
Pure virtual functions:

virtual void fun1()=0 -> must be overridden in the derived class

Virtual functions:

virtual void fun2() -> can be overridden

Normal functions:

void fun3() -> don't override it

In order to achieve runtime polymorphism you need to override virtual functions in c++
