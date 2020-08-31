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
///all the public and protected member of person act as 
///protected in student that they will not be visible to outsiders
///but to the derived from students
class Student: protected Person{
public:
    void display(){
        cout<<name<<endl;
    }
};

int main(){
    
}
