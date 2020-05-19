class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long int total=0;
        
        for(int i : nums)total+=i;
        
        if(total<S)return 0;
        
        long int s1 = (S+total)>>1;
        
        if((S+total)&1)return 0;
        long int dp[nums.size()+1][s1+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]==0)dp[i][0]=2*dp[i-1][0];
            else dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=s1;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0)dp[i][j]+=dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[nums.size()][s1];
    }
};
