class Solution {
public:
    vector<vector<int>>dp;
    int solve(string word1,string word2,int n,int m){
        if(n==0)return m;
        if(m==0)return n;
        if(dp[n][m]!=-1)return dp[n][m];
        if(word1[n-1]==word2[m-1]){
            return solve(word1,word2,n-1,m-1);
        }
        return dp[n][m]=1+(min(solve(word1,word2,n-1,m),min(solve(word1,word2,n,m-1),solve(word1,word2,n-1,m-1))));
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,word1.size(),word2.size());
        int n = word1.size();
        int m = word2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0)dp[i][j]=j;
                else if(j==0){
                    dp[i][j]=i;
                }else{
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }else{
                        dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    }
                }
            }
        }
        return dp[n][m];
    }
};
