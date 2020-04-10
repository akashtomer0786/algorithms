//https://www.geeksforgeeks.org/count-strings-can-formed-using-b-c-given-constraints/
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int dp[1001][2][3];
int solve(int n,int b,int c){
    if(n<=0){
        return 1;
    }
    if(b<=0 && c<=0)return 1;

    if(dp[n][b][c])return dp[n][b][c];

    if(b==0)dp[n][b][c] = solve(n-1,b,c-1) + solve(n-1,b,c);

    else if(c==0)dp[n][b][c]=solve(n-1,b-1,c) + solve(n-1,b,c);

    else dp[n][b][c] = solve(n-1,b-1,c) + solve(n-1,b,c-1) + solve(n-1,b,c);
    return dp[n][b][c];
}
int s(int n)
{
	int dp[n+1][2][3];
	memset(dp, 0, sizeof dp);
	
	for (int j=0;j<2;j++){
	    for (int k=0;k<3;k++){
	        dp[0][j][k] = 1;
	    }
	}
	
	for (int i=1;i<=n;i++){
	    for (int j=0;j<2;j++){
	        for (int k=0;k<3;k++){
	            int value = dp[i-1][j][k];
	            if (j>0) value+= dp[i-1][j-1][k];
	            if (k>0) value+= dp[i-1][j][k-1];
	            dp[i][j][k] = value;
	        }
	    }
	}
	
	return dp[n][1][2];
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<s(n)<<endl;
    }
}
