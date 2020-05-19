#include<bits/stdc++.h>
using namespace std;
int knapsack_0_1(vector<int>prices,vector<int>weight,int W){
    int n = prices.size();
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0)dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j];
                if(j-weight[i-1]>=0)dp[i][j]=max(prices[i-1]+dp[i-1][j-weight[i-1]],dp[i][j]);
            }
        }
    }
    int res = dp[n][W];
    int i=n;
    int j=W;
    ///now go reverse
    while(res>0&&j>0&&i>0){
        if(dp[i-1][j]==res){
            i--;///this ith item was not included go in previous row
        }else{
            cout<<weight[i-1]<<" ";
            res=res-prices[i-1];
            j=j-weight[i-1];
            i--; ///since repetition of items was not allowed
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>weight(n),prices(n);

        for(int i=0;i<n;i++)cin>>prices[i];
        for(int i=0;i<n;i++)cin>>weight[i];
        int W;
        cin>>W;






        knapsack_0_1(prices,weight,W);

    }
}
