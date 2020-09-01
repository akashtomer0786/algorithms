#include<iostream>
#include<memory>
#include<bits/stdc++.h>
using namespace std;


class Foo{
    int x;
public:
    Foo(int x):x{x}{
    }
    int getx(){return x;}
    ~Foo(){
        cout<<"Foo destructor"<<endl;
    }
};
void fun(std::shared_ptr<Foo> sp,int count){
    static std::mutex ml;
    std::lock_guard<mutex>loc(ml);
    cout<<" thread: "<<count<<" "<<sp.use_count()<<endl;
}

int main(){
//    shared_ptr<Foo>sp(new Foo(100));
//    cout<<sp->getx()<<endl;
//    cout<<sp.use_count()<<endl;
//    shared_ptr<Foo>sp1 = sp;
//    cout<<sp.use_count()<<endl;
//    cout<<sp1.use_count()<<endl;
//    ///if i do something like this
//    shared_ptr<Foo>&sp2 = sp;
    /// then count will not increase for reference and same goes with pointer

    ///comment above

    shared_ptr<Foo>sp(new Foo(100));
    cout<<"main before : "<<sp.use_count()<<endl;
    ///different threads using same new Foo pointer
    ///every time referenc value increase until we are not passing it to as refer or pointer
    thread t1(fun,sp,1),t2(fun,sp,2),t3(fun,sp,3);
    t1.join();
    t2.join();
    t3.join();
    return 0;

    return 0;
}
