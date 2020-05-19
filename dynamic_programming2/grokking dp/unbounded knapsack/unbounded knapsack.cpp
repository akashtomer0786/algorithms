#include<iostream>
using namespace std;
int solve(int prices[],int weight[],int W,int n){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=((i==0)||(j==0))?0:max((j-weight[i-1]>=0)?+prices[i-1]+dp[i][j-weight[i-1]]:0,dp[i-1][j]);
        }
    }
    return dp[n][W];
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int prices[n+1];
	    int weight[n+1];
	    int w;
	    cin>>w;
	    for(int i=0;i<n;i++){
	        cin>>prices[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>weight[i];
	    }
	    cout<<solve(prices,weight,w,n)<<endl;
	}
	return 0;
}
