#include<bits/stdc++.h>
using namespace std;

int dp[100+1][100+1];
int lcs(string a,string b){
    int n = a.size();
    int m = b.size();



    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
string printlcs(string a,string b,int i,int j){
    if(i==0||j==0)return "";

    if(a[i-1]==b[j-1]){
        return printlcs(a,b,i-1,j-1)+a[i-1];
    }

    if(dp[i-1][j]>dp[i][j-1]){
        return printlcs(a,b,i-1,j);
    }else{
        return printlcs(a,b,i,j-1);
    }

}
int main(){
    string a,b;
    cin>>a>>b;
    lcs(a,b);
    cout<<printlcs(a,b,(int)a.size(),(int)b.size());
}
