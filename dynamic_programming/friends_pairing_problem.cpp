#include<bits/stdc++.h>
#define int long long
#define mod  1000000007
using namespace std;


int friends_pair(int n){
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++){
        int i_want_to_remain_single=dp[i-1];
        int i_want_to_be_paired=((i-1)*dp[i-2]);
        dp[i] = (i_want_to_remain_single%mod + i_want_to_be_paired%mod)%mod;
    }
    return dp[n];
}
int32_t main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<friends_pair(n)<<endl;
	}
	return 0;
}
