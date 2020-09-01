#include<bits/stdc++.h>
using namespace std;
class Animal{
public:
    int age;
    void walk(){
        cout<<"animal walks"<<endl;
    }
};
class Tiger :virtual public Animal{

};
class Lion :virtual public Animal{

};
///In liger class there will be two instance of class Animal
///And that is called diamond problem

class Liger : public Tiger , public Lion {
    ///because of virtual keyword there will be only one
    ///instance of Animal in Liger
    ///And constructor will be called only once for Liger class


};
int main(){
    Liger obj;
    obj.walk();
}
