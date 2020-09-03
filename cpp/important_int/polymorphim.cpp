#include<bits/stdc++.h>
using namespace std;
class base{
public:
    int x;

    virtual void check(){
        cout<<"Hi I am from Base"<<endl;
    }
};
class child : public base{
public:
    virtual void check(){
        cout<<"Hi I am not from child"<<endl;
    }
};
int main(){
    child c;
    c.check();  ///it will print the definition of check function in child
    /// if not available in child then it will go in base class
    

    base* b = new child;
    b->check();
    ///it will bind at run time the behaviour of the check function will be decided
    /// at run time base on what type of pointer we put in base class pointer.
    /// if you don't override your virtual function in derived class then its
    /// definition will be taken from base class
}
