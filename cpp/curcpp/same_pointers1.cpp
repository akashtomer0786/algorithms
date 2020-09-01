#include<iostream>
#include<memory>
using namespace std;

There are few points about it:
0. shared_ptr is a smart pointer which can share the ownership of object (managed object).
1. Several shared_ptr can point to the same object (managed object).
2. It keep a reference count to maintain how many shared_ptr are pointing to the same object.
   and once last shared_ptr goes out of scope then the managed object gets deleted.
3. shared_ptr is threads safe and not thread safe. [what is this??]
   a. control block is thread safe
   b. managed object is not
4. There are three ways shared_ptr will destroyed managed object.
   a. If the last shared_ptr goes out of scope.
   b. If you initialize shared_ptr with some other shared_ptr.
   c. If you reset shared_ptr.
5. Reference count doesn't work when we use reference or pointer of shared_ptr.
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

int main(){
    shared_ptr<Foo>sp(new Foo(100));
    cout<<sp->getx()<<endl;
    cout<<sp.use_count()<<endl;
    shared_ptr<Foo>sp1 = sp;
    cout<<sp.use_count()<<endl;
    cout<<sp1.use_count()<<endl;
    ///if i do something like this
    shared_ptr<Foo>&sp1 = sp;
    /// then count will not increase for reference and same goes with pointer
    return 0;
}
