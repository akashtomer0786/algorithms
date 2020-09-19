#include<bits/stdc++.h>
using namespace std;
class base{
public:
    base(){
        cout<<"constructing base"<<endl;
    }
    virtual ~base(){
        cout<<"destructing base"<<endl;
    }
};
class derived: public base{
public:
    derived(){
        cout<<"constructing derived"<<endl;
    }
    ~derived(){
        cout<<"destructing derived"<<endl;
    }
};
int main(){
    /// base b;
    ///return 0; ///destruct will be called here for base b
    ///derived d;

    ///weird thing will not be happening if i simply write this derived d
    ///here first derived destructor will be called
    ///and this derived destructor will be calling base destructor

    /// weird thing will happen

    base *b = new derived;

    /// if i don't delete b no destructor will be called

    delete b; /// now destructor will be called

    ///derived destructor is not called because pointer is of base class
    /// only base destructor will be called;

    ///to call derived destructor make base class virtual destructor



}
