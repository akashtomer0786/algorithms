//https://practice.geeksforgeeks.org/problems/number-of-coins/0
#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int>a;
int32_t main()
 {
	int t;
	cin>>t;
	while(t--){
	    
	    int val,n;
	    cin>>val>>n;
	    a.resize(n);
	    for(int i=0;i<n;i++)
	       cin>>a[i];
	    int dp[val+1];
	    for(int i=0;i<=val;i++){
	        dp[i]=INT_MAX;
	    }
	    dp[0]=0;
	    int ans=INT_MAX;
	    for(int i=0;i<n;i++){
	        for(int j=1;j<=val;j++){
	            
	            if(j-a[i]>=0){
	                dp[j]=min(1+dp[j-a[i]],dp[j]);
	            }
	            //if(j==val && dp[j]!=0)ans=min(ans,dp[j]);
	        }
	    }
	    if(dp[val]==INT_MAX)dp[val]=-1;
	    cout<<dp[val]<<endl;
	}
	return 0;
}
