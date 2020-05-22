class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
       long long  int dp[amount+1];
        fill(dp,dp+amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                dp[j]=min(dp[j],1LL*dp[j-coins[i-1]]+1);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
