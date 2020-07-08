
Virtual functions are used with inheritance, they are called according to the type of object pointed or referred,
not according to the type of pointer or reference. In other words, virtual functions are resolved late, at runtime. 
Virtual keyword is used to make a function virtual.

Following things are necessary to write a C++ program with runtime polymorphism (use of virtual functions)
1) A base class and a derived class.
2) A function with same name in base class and derived class.
3) A pointer or reference of base class type pointing or referring to an object of derived class.

For example, in the following program bp is a pointer of type Base, but a call to bp->show() calls 
show() function of Derived class, because bp points to an object of Derived class.

#include<iostream> 
using namespace std; 

class Base { 
public: 
	virtual void show() { cout<<" In Base \n"; } 
}; 

class Derived: public Base { 
public: 
	void show() { cout<<"In Derived \n"; } 
}; 

int main(void) { 
	Base *bp = new Derived;	 
	bp->show(); // RUN-TIME POLYMORPHISM 
	return 0; 
}
