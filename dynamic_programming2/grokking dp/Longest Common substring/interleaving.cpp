class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string s1,string s2,string s3,int n,int m){
        if(n==0)return s2.substr(0,m)==s3.substr(0,m+n);
        if(m==0)return s1.substr(0,n)==s3.substr(0,m+n);
        if(dp[n][m]!=-1)return false;
        if(s1[n-1]==s3[m+n-1]){
            if( solve(s1,s2,s3,n-1,m))return true;
        }
        if(s2[m-1]==s3[m+n-1]){
            if(solve(s1,s2,s3,n,m-1))return true;
        }
        return dp[n][m]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
       return solve(s1,s2,s3,s1.size(),s2.size());
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n+m!=s3.size())return false;
        bool dp[n+1][m+1];
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            if(s1[i-1]==s3[i-1])dp[i][0]=dp[i-1][0];
            else dp[i][0]=false;
        }
        for(int i=1;i<=m;i++){
            if(s2[i-1]==s3[i-1])dp[0][i]=dp[0][i-1];
            else dp[0][i]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=false;
                if(s1[i-1]==s3[i+j-1])dp[i][j]=dp[i-1][j];
                if(s2[j-1]==s3[i+j-1])dp[i][j]=dp[i][j]||dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};
