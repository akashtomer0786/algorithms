//https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0

#include<bits/stdc++.h>
using namespace std;
int dp[1001][2][3];
int solve(int n,int b,int c){
    if(n<=0){
        return 1;
    }
    if(b<=0 && c<=0)return 1;

    if(dp[n][b][c])return dp[n][b][c];

    if(b==0)dp[n][b][c] = solve(n-1,b,c-1) + solve(n-1,b,c);

    else if(c==0)dp[n][b][c]=solve(n-1,b-1,c) + solve(n-1,b,c);

    else dp[n][b][c] = solve(n-1,b-1,c) + solve(n-1,b,c-1) + solve(n-1,b,c);
    return dp[n][b][c];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n,1,2)<<endl;
    }
}
