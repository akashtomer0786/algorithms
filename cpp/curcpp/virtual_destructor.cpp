#include<bits/stdc++.h>
using namespace std;
class Person{
protected:
    string name;
public:
    void setName(string iname){
        name=iname;
    }
};
class Student : public Person{
public:
    void display(){
        cout<<name<<endl;
    }
};

///in public inheritance
///all public will remain as public
///all protected will remain protected in derived
///all private will remain private in derived

int main(){
    Student akash;
    akash.name = "akash"; ///error
    akash.setName("akash");
    akash.display();
}
