#include<bits/stdc++.h>
using namespace std;
int dec_to_oct(int n){
    int ans=0;
    int p=1;
    while(n){
        ans=ans+(n%8)*p;
        n=n/8;
        p=p*10;
    }
    return ans;
}
int oct_to_dec(int n){
    int ans = 0;
    int p=1;
    while(n){
        ans+=(p*(n%10));
        n=n/10;
        p*=8;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int val = dec_to_oct(n);
        cout<<dec_to_oct(n)<<endl;

        cout<<oct_to_dec(val)<<endl;
    }
}
