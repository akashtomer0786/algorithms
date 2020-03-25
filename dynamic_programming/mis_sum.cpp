#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int dp[n];
	    dp[0]=a[0];
	
	    int msis=dp[0];
	    for(int i=1;i<n;i++){
	        int prevmax=0;
	        for(int j=0;j<i;j++){
	            if(prevmax<dp[j] && a[i]>a[j])prevmax = dp[j];
	        }
	        dp[i]=prevmax+a[i];
	        msis=max(dp[i],msis);
	    }
	    cout<<msis<<endl;
	}
	return 0;
}
