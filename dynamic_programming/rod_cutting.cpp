

#include<bits/stdc++.h>
using namespace std;
int cutrod(int price[],int n){
    if(n<=0)return 0;

    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        ans=max(ans,price[i]+cutrod(price,n-i-1));
    }
    return ans;
}
int cutrod1(int price[],int n){
    int dp[n+1];
    dp[0]=0;
    for(int len=1;len<=n;len++){
            dp[len]=0;
        for(int k=1;k<=len;k++){
             //   cout<<len-1<<"  "<<k-1<<endl;
            dp[len]=max(price[k-1]+dp[len-k],dp[len]);
        }
    }
    return dp[n];
}
int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<cutrod1(arr,8)<<endl;
}
