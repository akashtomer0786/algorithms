
#include <iostream>
using namespace std;

class A {
public:
    virtual void print() {
        cout << "I am in class A" << endl;
    }
};

class B : public A {
public:
    void print() {
        cout << "I am in class B" << endl;
    }
};

class C : public B {
public:
    void print() {
        cout << "I am in class C" << endl;
    }
};

int main() {
    A* ptr1 = new A();
    ptr1->print(); /// Output: I am in class A

    A* ptr2 = new B();
    ptr2->print(); /// Output: I am in class B

    A* ptr3 = new C();
    ptr3->print(); /// Output: I am in class C


    return 0;
}
