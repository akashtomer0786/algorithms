#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int bitonic(int n){
    int lis[n];
    int lds[n];
    for(int i=0;i<n;i++){
        lis[i]=1;
        lds[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
                lis[i]=max(lis[i],lis[j]+1);
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j])
                lds[i]=max(lds[i],lds[j]+1);
        }
    }
    int mx = lis[0]+lds[0]-1;
    for(int i=1;i<n;i++)
        mx=max(mx,lis[i]+lds[i]-1);
    return mx;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);

        for(int i=0;i<n;i++)cin>>a[i];

        cout<<bitonic(n)<<endl;
    }
}
