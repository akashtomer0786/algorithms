class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1)return false;
        bool dp[n+1][sum/2+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum/2;j++){
                if(i==0)dp[i][j]=false;
                else if(j==0)dp[i][j]=true;
                else{
                    dp[i][j]=dp[i-1][j];
                    if(j-nums[i-1]>=0)dp[i][j]|=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum/2];
    }
};
