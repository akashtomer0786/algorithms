class Solution {
public:
    //dp[i][j] elements having till i can we form sum equal to j
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

class Solution {
public:
    int dp[200+1][100*200+1];
    bool solve(int sum,int i,vector<int>&nums){
        if(i<0||sum<0)return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(sum==0)return true;
        
        return dp[i][sum]=solve(sum-nums[i],i-1,nums)||solve(sum,i-1,nums);
    }
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i : nums)sum+=i;
        if(sum&1)return false;
        memset(dp,-1,sizeof(dp));
        return solve(sum/2,(int)nums.size()-1,nums);
    }
};
class Solution {
public:
    int dp[200+1][100*200+1];
    bool solve(int sum,int i,vector<int>&nums){
        if(i<0||sum<0)return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(sum==0)return true;
        for(int j=i;j>=0;j--){
            if(solve(sum-nums[j],j-1,nums))return dp[i][sum]=true;
        }
        return dp[i][sum]=false;
    }
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i : nums)sum+=i;
        if(sum&1)return false;
        memset(dp,-1,sizeof(dp));
        return solve(sum/2,(int)nums.size()-1,nums);
    }
};
