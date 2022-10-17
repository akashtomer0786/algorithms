#include<bits/stdc++.h>

/**
Destructors are usually used to deallocate memory and do other cleanup 
for a class object and its class members when the object is destroyed
**/
using namespace std;
class base{
protected:
    ~base(){
        cout<<"base destructor called"<<endl;
    };
};
class derived:public base{

};
int main(){
    base b;   ///will not compile as here mail will call the destructor of base which it doesn't have access so error
    derived d;  ///will compile because child will call the destructor of parents and it has access to the parents protected member
    base* x = new base; ///will compile because compiler will think that its programmer responsibility to deallocate the memory
    delete x;      /// will not compile again  delete will call the destructor of base but doesn't have access that to
    
    ///point to be noted that in derived d 
    ///the main can call only derived::x  so main is not calling any function of base class
}
