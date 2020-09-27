#include<bits/stdc++.h>
using namespace std;
int add(int a,int b){
    return a+b;
}

void solve(int (*add)(int,int)){
    cout<<add(2,2)<<endl;
}

int main(){
    int a = 10;
    int b = 11;

    solve(add);

    ///another version
    int (*funptr)(int,int)=add;

    cout<<funptr(4,4)<<endl;

}
