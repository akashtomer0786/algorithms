class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        for(int i=1;i<=n;i++){
            dp[i]=100000000;
        }
        ///i is assigned as max value here
        dp[1]=0;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(i%j==0){
                    dp[i]=min(dp[j]+i/j,dp[i]);
                    break;
                }
            }
        }
        return dp[n];
    }
};
