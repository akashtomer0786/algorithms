///if i made a protected constructor then its object cannot be created 
#include<bits/stdc++.h>
using namespace std;
class base{
protected:
    base(){
        cout<<"constructing base"<<endl;
    }

};
class derived: public base{
public:
    derived(){
        /// base b; see this will give error
        cout<<"constructing derived"<<endl;
    }
};
int main(){
    ///base b;  ///so it seems that we have made the base class an abstract class without pure virtual function , its object cannot be created
    /// but the classes whose inherited from this base their object can be created because they  have access to protected base constructor
    derived d;
}
