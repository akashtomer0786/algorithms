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
///X     Y     Diff     Borrow
///0     0     0     0
///0     1     1     1
///1     0     1     0
///1     1     0     0
int subtract(int x,int y){
    ///iterate till there is no carry
    while(y!=0){
        ///borrow contains common set bits of y
        ///and unset bits of x
        int borrow = (~x)&y;
        ///subtraction of bits of x
        ///and y where at least one of
        ///the bits is not set
        x = x^y;

        ///Borrow is shifted by one
        ///so that subtracting it from
        ///x gives the required sum
        y = borrow<<1;
    }
    return x;
}
int divide(int dividend,int divisor){
    int sign = ((dividend<0)^(divisor<0))?-1:1;
    dividend = abs(dividend);
    divisor = abs(divisor);

    long long quotient = 0,temp=0;
    for(int i=31;i>=0;i--){
        if(temp+(divisor<<i)<=dividend){
            temp+=divisor<<i;
            quotient|=1LL<<i;
        }
    }
    return sign*quotient;
}
int multiply(int a,int b){
    int res=0;
    while(b>0){
        if(b&1){
            res=res+a;
        }
        b>>=1;
        a<<=1;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<multiply(a,b)<<endl;
    }
}
