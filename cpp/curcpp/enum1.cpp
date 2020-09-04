#include<bits/stdc++.h>
using namespace std;
enum State {working=1,failed=0};
enum week  {Mon , Tue , Wed , Thur , Fri , Sat , Sund};

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
