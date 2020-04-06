//https://practice.geeksforgeeks.org/problems/path-in-matrix/0/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>a[i][j];
	        }
	    }
	    
	    vector<int>dp(n);
	    vector<int>pre(n);
	    int ans=INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(i==0){
	                dp[j]=a[i][j];
	            }else{
	                if(j-1>=0)dp[j]=max(pre[j],pre[j-1]);
	                if(j+1<n)dp[j]=max(dp[j],pre[j+1]);
	                dp[j]+=a[i][j];
	            }
	            if(i==n-1){
	                ans = max(dp[j],ans);
	            }
	        }
	        pre=dp;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
