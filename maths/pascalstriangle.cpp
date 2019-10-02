// Project Euler 53
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int32_t main(){
    int maxNumber=1000000;
    int num;
    cin>>num>>maxNumber;
    vector<vector<int>> combinations(num+1);
    for(int i=0;i<=num;i++){
       combinations[i].resize(i+1,0);
       combinations[i][0]=combinations[i][i]=1;
    }
    int ans = 0;
    for(int i=1;i<=num;i++){
        for(int j=1;j<i;j++){
            combinations[i][j]=combinations[i-1][j-1]+combinations[i-1][j];
            if(combinations[i][j]>maxNumber){
                combinations[i][j]>maxNumber+1;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
