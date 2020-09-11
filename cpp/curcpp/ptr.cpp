#include<bits/stdc++.h>
using namespace std;


int main(){
    int l = 5;
    int *ptr = &l;
    ///comment one by one and check
    //int x = *ptr++;
    int y = *++ptr;
    int z = ++*ptr;
    int k = (*ptr)++;
    //cout<<x<<" x"<<endl;
    cout<<y<<" y"<<endl;
    cout<<z<<" z"<<endl;
    cout<<k<<" k"<<endl;
}
