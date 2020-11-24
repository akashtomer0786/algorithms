#include<bits/stdc++.h>
using namespace std;
int main(){
    int val = 5;
    int *ptr = &val;

    --(*ptr);  ///this will change the value inside ptr;
    (*ptr)--;  ///this will change the value inside ptr
    *ptr++; ///this will perform arithmatic operation on ptr
    
    /// from stackoverflow  *ptr++ - going from left-to-right, dereference the pointer, and then increment the pointer value (not what it points to, due to the precedence of postfix over dereference)
    ///above there is error
    cout<<ptr<<endl;
    *ptr++;
    cout<<ptr-1<<endl;

    ptr++;
   // cout<<endl;
}
