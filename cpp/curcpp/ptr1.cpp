#include<bits/stdc++.h>
using namespace std;
int main(){
    int val = 5;
    int *ptr = &val;

    --(*ptr);  ///this will change the value inside ptr;
    (*ptr)--;  ///this will change the value inside ptr
    *ptr++; ///this will perform arithmatic operation on ptr
    cout<<ptr<<endl;
    *ptr++;
    cout<<ptr-1<<endl;

    ptr++;
   // cout<<endl;
}
