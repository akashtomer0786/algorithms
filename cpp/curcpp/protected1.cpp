#include<iostream>
#include<vector>
using namespace std;

class base{
protected:
    int x;
};
class derived : protected base {
private:
    some(){

        /// we confused how to use protected member here
        ///doing some thing like
        /// base o
        /// o.x; will be wrong

        ///correct way here 
        ///because this is already inherited to this class
        cout<<x<<endl;


    }
};


int main(){


    int a=2;
    int &p = a;
    cout<<p<<endl;


}
