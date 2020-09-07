#include<bits/stdc++.h>
using namespace std;
class person{
protected:
    string name;
public:
    void setname(string iname){
        name = iname;
    }
};
///all the private and protected member of person
///now act as private in person
///this means that they can be accessed in student class but
/// but not outside the class


/// see private cannot be accessed above you are wrong private cannot be accessed any where insided class 
/// see here https://www.geeksforgeeks.org/inheritance-in-c/
class student : private person{
public:
    void display(){
        cout<<name<<endl;
    }
    void setnamehere(string nam){
        setname(nam);
    }
};
class Gstudent : public student{
public:
    void setStudentName(string iname){
        ///name = iname; error here because name is inherited as private in person

        ///what we can do call any public member of person
        setnamehere(iname);
    }
};
int main(){
    Gstudent akash;
    akash.setStudentName("akash");
}
