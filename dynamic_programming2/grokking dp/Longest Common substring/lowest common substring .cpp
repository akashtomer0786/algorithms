int solve(string a,string b){
    int n = a.size();
    int m = b.size();
    
    int ans=0;
    
    int dp[m+1];
    fill(dp,dp+m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(a[i-1]==b[j-1]){
                dp[j]=1+dp[j-1];
            }else dp[j]=0;
            ans=max(dp[j],ans);
        }
        
    }
    
    return ans;
}
int solve(string a,string b){
    int n = a.size();
    int m = b.size();
    int ans=0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)dp[i][j]=0;
            else{
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
