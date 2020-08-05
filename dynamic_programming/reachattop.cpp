#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    dp[1][0]=1;
    dp[2][0]=2;
    for(int i=3;i<=n;i++){
        dp[i][0]=dp[i-1][0] + dp[i-2][0];
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]+=dp[i-3][j-1]+dp[i-1][j]+dp[i-2][j];
        }
    }
    int ans=0;
    for(int j=0;j<=k;j++){
        ans+=dp[n][j];
    }
    cout<<ans<<endl;
}
