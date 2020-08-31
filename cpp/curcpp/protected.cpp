#include<bits/stdc++.h>
using namespace std;
class Base{
protected:
    void fun(){
        cout<<"Hello I am from Base "<<endl;
    }
};
class Derived: public Base{
public:
    void fun2(){
        fun(); ///fun is accessible in derived being a protected member
    }
};

int main(){
    Base *b1 = new Base();
    Derived *b2 = new Derived();

    //b1->fun();
    b2->fun2();

    delete b1;
    //delete b2;
    return 0;
}
