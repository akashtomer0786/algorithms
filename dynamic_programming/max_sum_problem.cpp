//https://practice.geeksforgeeks.org/problems/maximum-sum-problem/0
#include<iostream>
using namespace std;
int solve(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return max(solve(n/2)+solve(n/3)+solve(n/4),n);
}
int solve1(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i/2]+dp[i/3]+dp[i/4],i);
    }
    return dp[n];
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<solve(n)<<endl;
	}
	return 0;
}
