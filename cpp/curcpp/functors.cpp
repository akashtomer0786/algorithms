#include<iostream>
using namespace std;
///Functor work as function and achieved by overloading operator () in some class
///what is the reason for functor use
///They save the state of the function but if we
///are using traditional function then doesn't save state

///functors are objects used as function
///they save state
class multiply{
    int _val;
public:
    multiply(){

    }
    multiply(int val):_val{val}{

    }
    int operator () (int val){
        return val*_val;
    }

};
int main(){
    multiply mul12(12);

    cout<<mul12(2)<<endl;
    cout<<mul12(3)<<endl;

}
