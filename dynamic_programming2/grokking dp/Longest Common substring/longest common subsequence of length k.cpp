#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int k;
        cin>>k;
        int dp[n][k+1];
        ///dp[i][j] would be denoting here the subsequnce of length j and ending at i position
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][1]=1;
        }
        for(int len=2;len<=k;len++){
            for(int i=0;i<n;i++){

                for(int j=0;j<i;j++){
                    if(a[j]<a[i]){
                        dp[i][len]+=dp[j][len-1];
                    }
                }
            }
        }
        int ans=0;
        for(int i=k-1;i<n;i++){
            ans+=dp[i][k];
        }
        cout<<ans<<endl;
    }
}
