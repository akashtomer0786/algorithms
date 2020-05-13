#include<bits/stdc++.h>
using namespace std;
int add(int x,int y){
    while(y!=0){
        int carry=x&y;
        x=x^y;

        y=carry<<1;
    }
    return x;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<add(a,b)<<endl;
    }
}
