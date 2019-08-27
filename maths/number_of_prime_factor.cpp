#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
const int N = 5e6+1;
int dp[N]={};
int isprime[N];
int ans[N]={};

void cnt_prime_factors(){
    for(int i=0;i<N;i++){
        isprime[i]=1;
    }
    isprime[0]=isprime[1]=0;
    for(int i=2;i*i<N;i++){
        if(isprime[i]==1){
            for(int j=2;j*i<N;j++){
                isprime[i*j]=i;
            }
        }
    }
    dp[0]=dp[1]=0;
    dp[2]=dp[3]=1;
    for(int i=4;i<N;i++){
        dp[i]=1+dp[i/isprime[i]];
    }
    for(int i=1;i<N;i++){
        ans[i]=ans[i-1]+dp[i];
    }
}
int main(){
    FAST;
    int t;
    cin>>t;

    cnt_prime_factors();
    while(t--){
        int a,b;
        cin>>a>>b;
        //cout<<dp[a];
        cout<<ans[a]-ans[b]<<"\n";

    }
}
