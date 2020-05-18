
///dp[i][j] represents the score of player in action more than opponent (second player) will get from i to j 
///First in action whoever moves first 
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        for(int i=0;i<n;i++)dp[i][i]=nums[i];
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j = i+len-1;
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};
