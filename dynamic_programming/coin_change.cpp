//https://www.geeksforgeeks.org/coin-change-dp-7/
#include<bits/stdc++.h>
using namespace std;
int ans=0;
vector<int>a;

void coin_change(int m){
    int n=a.size();
    int dp[m+1];
    
    dp[0]=1;
    for(int i=0;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            int x=0,y=0;
            if(j-a[i]>=0)x=dp[j-a[i]];
            if(i-1>=0)y=dp[j];
            dp[j]=x+y;
        }
    }
    ans = dp[m];
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    ans=0;
	    int n;
	    cin>>n;
	    a.resize(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    //sort(a.begin(),a.end());
	    coin_change(m);
	    cout<<ans<<endl;
	    
	}
	return 0;
}
