//Given two strings S1 and S2, find the number of times the second string occurs in the first string, whether continuous or discontinuous.

#include<bits/stdc++.h>
using namespace std;
int solve(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int a;
	    cin>>a>>a;
	    string s1,s2;
	    cin>>s1>>s2;
	    cout<<solve(s1,s2)<<endl;
	}
	return 0;
}
