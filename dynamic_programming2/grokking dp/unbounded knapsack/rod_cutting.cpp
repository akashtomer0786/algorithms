#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int rod_cutting(int n){
    int dp[n+1][n+1];
    ///dp[i][j] we have pieces till i ,i-1 ...1 length we want to minimise the legth of j
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j];
                if(j-i>=0)dp[i][j]=max(dp[i][j],dp[i][j-i]+a[i-1]);
            }
        }
    }
    return dp[n][n];
}
int rod_cutting1(int n){
    if(n==0)return 0;
    int res=0;
    for(int i=1;i<=n;i++){
        res=max(res,a[i-1]+rod_cutting(n-i));
    }
    return res;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    a.resize(n);
	    for(int i=0;i<n;i++)cin>>a[i];
	    cout<<rod_cutting1(n)<<endl;
	}
	return 0;
}
