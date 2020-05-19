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
    return dp[n][W];
}
int dp[1000+9][1000+9];
int knapsack_0_1(int i,vector<int>prices,vector<int>weight,int W){

    if(i<=0 || W<=0)return 0;
    if(dp[i][W]!=-1)return dp[i][W];
    int val = 0;
    if(W-weight[i-1]>=0){
        val = prices[i-1] + knapsack_0_1(i-1,prices,weight,W-weight[i-1]);
    }
    return dp[i][W]=max(val,knapsack_0_1(i-1,prices,weight,W));

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>weight(n),prices(n);
        int W;

        cin>>W;
        for(int i=0;i<n;i++)cin>>prices[i];
        for(int i=0;i<n;i++)cin>>weight[i];

        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=W;j++)dp[i][j]=-1;


        cout<<knapsack_0_1(n,prices,weight,W)<<endl;

    }
}
