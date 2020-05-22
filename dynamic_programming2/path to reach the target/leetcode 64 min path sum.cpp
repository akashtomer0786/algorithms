class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)return 0;
        int m = grid[0].size();
        int dp[m+1];
        dp[0]=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1)dp[j]=j-1>=1?dp[j-1]+grid[i-1][j-1]:grid[i-1][j-1];
                else {
                    dp[j]=min(dp[j-1],dp[j])+grid[i-1][j-1];
                }
            }
            for(int i=0;i<=m;i++){
                cout<<dp[i]<<endl;
            }
        }
        for(int i=0;i<=m;i++){
            cout<<dp[i]<<" ";
        }
        return dp[m];
    }
};
