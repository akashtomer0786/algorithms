#include<bits/stdc++.h>
using namespace std;
enum State {working=1,failed=0};
enum week  {Mon , Tue , Wed , Thur , Fri , Sat , Sund};

Enumeration is a user defined datatype in C language.
It is used to assign names to the integral constants which makes a program easy to read and maintain. The keyword “enum” is used to declare an enumeration.

int main(){
    State mymachinestate = failed;
    if(mymachinestate){
        cout<<"My machine is working"<<endl;
    }else{
        cout<<"My machine is not working"<<endl;
    }

    week today = Thur;

    if(today==Thur){
        cout<<Fri<<endl;
    }
}
