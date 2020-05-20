#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b){
    int dp[a.size()+1][b.size()+1];
    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else {
                if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //cout<<"# "<<dp[a.size()][b.size()]<<endl;
    int delete_operations = a.size()-dp[a.size()][b.size()];
    int insert_operations = b.size()-dp[a.size()][b.size()];
    return delete_operations+insert_operations;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    string a,b;
	    cin>>a>>b;
	    cout<<lcs(a,b)<<endl;
	    
	}
	return 0;
}
