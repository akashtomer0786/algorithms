#include<bits/stdc++.h>
using namespace std;
vector<int>a;

int dp[100][100];
void display(vector<int>p){
    for(int i : p)cout<<i<<" ";
    cout<<endl;
}
bool subset(int sum){
    int n = a.size();

    if(n==0||sum<0)return false;

    for(int i=0;i<=n;i++)dp[i][0]=true;

    for(int j=1;j<=sum;j++)dp[0][j]=false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(j-a[i-1]>=0){
                dp[i][j]=dp[i][j]||dp[i-1][j-a[i-1]];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][sum];
}
void print(vector<int>&a,int i,int sum,vector<int>p){
    if(sum==0){
        display(p);
        return;
    }
    if(dp[i-1][sum]){
        vector<int>b=p;
        print(a,i-1,sum,b);
    }
    if(sum-a[i-1]>=0&&dp[i][sum-a[i-1]]){
        p.push_back(a[i-1]);
        print(a,i-1,sum-a[i-1],p);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int sum;
        cin>>sum;
        if(subset(sum)){
            print(a,n,sum,{});
        }
    }
}
