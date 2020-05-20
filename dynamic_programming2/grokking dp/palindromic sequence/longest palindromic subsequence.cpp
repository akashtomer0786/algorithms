class Solution {
public:
    vector<vector<int>>dp;
    int solve(int a,int b,string s){
        if(a<0||b<0)return 0;
        if(b-a==0)return 1;
        if(b-a<0)return 0;
        if(dp[a][b]!=-1)return dp[a][b];
        if(s[a]==s[b]){
            return dp[a][b]=2+solve(a+1,b-1,s);
        }
        return dp[a][b]=max(solve(a,b-1,s),solve(a+1,b,s));
    }
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s);

    }
};

class Solution {
public:
    vector<vector<int>>dp;
    int solve(int a,int b,string s){
        if(a<0||b<0)return 0;
        if(b-a==0)return 1;
        if(b-a<0)return 0;
        if(dp[a][b]!=-1)return dp[a][b];
        if(s[a]==s[b]){
            return dp[a][b]=2+solve(a+1,b-1,s);
        }
        return dp[a][b]=max(solve(a,b-1,s),solve(a+1,b,s));
    }
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s);

    }
};
