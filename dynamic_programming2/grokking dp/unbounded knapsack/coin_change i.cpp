class Solution {
public:
     
    vector<vector<int>>dp;

int solve(vector<int>&a,int n,int v){
   // string s = to_string(n) + " " +to_string(v);
    if(dp[n][v]!=-1)return dp[n][v];
    if(v==0)return 0;
    if(n==0)return INT_MAX;
    if(v<0)return INT_MAX;
    long long int val = v-a[n-1]>=0?1+1LL*solve(a,n,v-a[n-1]):INT_MAX;
    //val=INT_MAX;
    return dp[n][v]=min(1LL*val,1LL*solve(a,n-1,v));
}
    int coinChange(vector<int>& coins, int amount) {
        
        dp.resize(coins.size()+1,vector<int>(amount+1,-1));
        long long int ans= solve(coins,(int)coins.size(),amount);
        return ans>=INT_MAX?-1:ans;
        
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        fill(dp,dp+amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                dp[j]=min(dp[j],dp[j-coins[i-1]]+1);
            }
        }
        return dp[amount]>=amount+1?-1:dp[amount];
    }
};
