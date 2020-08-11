#include<bits/stdc++.h>
using namespace std;
///function overloading
class profile{
public:
    string phone[2];

    void getphone(string phone1){
        phone[0]=phone1;
    }
    void getphone(string phone1,string phone2){
        phone[0]=phone1;
        phone[1]=phone2;
    }
};
int main(){
    class profile profile1;
    profile1.getphone("12345","345345");
}
