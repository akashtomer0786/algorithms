#include<iostream>
#include<memory>

///we are going to wrap our class inside unique pointer
using namespace std;
class Foo{
    int x;
public:
    explicit Foo(int x):x{x}{}
    int getx(){
        return x;
    }
    ~Foo(){
        cout<<"Foo Dest"<<endl;
    }
};
int main(){
    Foo *f = new Foo(10);
    cout<<f->getx()<<endl; /// in this case we have memory leak if we are not clearing this

    delete f;  ///one most important thing destructor will be called only when we are
    ///writing this statement delete f because since the memory is dynamically allocated
    ///its need to be cleared explicitly

    ///in below  place p seems to be a object on heap but not it is on stack
    ///and when any variable goes out of scope on stack destructor will be
    /// called unlike heap

    ///what below declaration show we are creating local object of unique_ptr p1
    ///on stack and passing pointer new Foo(10) to the constructor of unique_ptr
    unique_ptr<Foo>p1(new Foo(10)); ///in this we don't have because the Foo clase destructor
    ///will destroy the object

    ///Actually this works when we put a pointer insided a class object then it becomes
    ///local to that class scope and when this class object goes out of scope
    ///the object vanishes including this pointer to
    cout<<p1->getx()<<endl;

    /// so we can sya that in above statement that in destructor of unique_ptr
    /// the pointer new Foo(10) will be destroyed

    ///Finaaly the destructor of unique_ptr will call delete on passing pointer
    ///which will lead to calling of destructor of Foo too because of delete

    unique_ptr<Foo> p2 = make_unique<Foo>(20); ///other way of declaring unique pointer

    cout<<p1->getx()<<(*p2).getx()<<endl;


    ///p1=p2 will fail we cannot copy ownership

    ///so to move ownership we can do something like this
    unique_ptr<Foo> p3 = move(p1);
    ///now p1 will become null and what p1 has is now on p3 and p1 is null

    Foo* p = p3.get(); ///it will return the pointer it holding

    return 0;

    return 0;
}
