#include<iostream>
using namespace std;
/// sizeof empty struct is 0 in c
/// sizeof empty struct or empty class is 1 in cpp


struct Base1{

};
class Base{
};
int main(){
    ///suppose if i create empty class object
    Base a,b;
    ///we know base is empty class but to identify completely
    ///the object a and b compiler allocates them one byte

    ///But suppose if class contains a int like this

    class B{
        int x;
        int y;
        void fun(){
        cout<<"is the size of fun addes in size of class"<<endl;
        ///Answer NO
        }
    };

    cout<<sizeof(B)<<endl;
    
    /// in this size will be not 8+1 because 8 byte is enough them 
    /// identify two objects uniquely
}
