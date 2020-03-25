//https://practice.geeksforgeeks.org/problems/count-number-of-hops/0/
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int dp[n+1];
	    dp[0]=1;
	    for(int i=1;i<=n;i++){
	        if(i-1>=0)dp[i]=dp[i-1];
	        if(i-2>=0)dp[i]+=dp[i-2];
	        if(i-3>=0)dp[i]+=dp[i-3];
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
