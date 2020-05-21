#include<bits/stdc++.h>
using namespace std;
int solve(string a,string b){
    ///for iterative length of a + length of b - length of lcs
}
int solve_recursive(char *X,char *Y,int lenx,int leny){
    if(!lenx)return leny;
    if(!leny)return lenx;
    if(X[lenx-1]==Y[leny-1])return 1+solve_recursive(X,Y,lenx-1,leny-1);
    return 1+min(solve_recursive(X,Y,lenx-1,leny),solve_recursive(X,Y,lenx,leny-1));
}
///scs bottom up solve
int solve(string a,string b){
    int n = a.size();
    int m = b.size();
    
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
            }
        }
    }
    return dp[n][m];
}
///scs recursive printing 
string scs(string x,string y,int m,int n){
    if(m==0)return y.substr(0,n);
    if(n==0)return x.substr(0,m);

    if(x[m-1]==y[n-1])
        return scs(x,y,m-1,n-1)+x[m-1];
    if(dp[m-1][n]<dp[m][n-1])///since we want to minimise the length of super sequence move in opposite direction
        return scs(x,y,m-1,n)+x[m-1];
    else
        return scs(x,y,m,n-1)+y[n-1];
}
///scs iterative printing 
string scs_iterative(string a,string b){
    string ans="";
    ///traverse the dp table from bottom right corner
    int i = a.size();
    int j = b.size();
    cout<<dp[i][j]<<endl;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans+=a[i-1];
            i--,j--;
        }else{
            ///move according to the dp table
            ///think we want to minimise the length of super sequence
            if(dp[i][j-1]<dp[i-1][j]){ ///beautiful think here
                ans+=b[j-1],j--;;
            }else ans+=a[i-1],i--;
        }
    }
    while(i>0){
        ans+=a[i-1];
        i--;
    }
    while(j>0){
        ans+=b[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        char a[1000];
        char b[1000];
        cin>>a>>b;
        int lenx = strlen(a);
        int leny = strlen(b);
        cout<<solve_recursive(a,b,lenx,leny)<<endl;
    }
}
