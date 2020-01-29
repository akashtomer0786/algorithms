https://www.techiedelight.com/longest-common-subsequence-finding-lcs/

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
vector<string>print_all_possible_lcs(string a,string b,int i,int j){
    if(i==0||j==0){
        return {""};
    }

    if(a[i-1]==b[j-1]){
        auto v = print_all_possible_lcs(a,b,i-1,j-1);

        for(auto &s: v){
            s.push_back(a[i-1]);
        }
        return v;
    }

    if(dp[i-1][j]>dp[i][j-1]){
        return print_all_possible_lcs(a,b,i-1,j);
    }
    if(dp[i][j-1]>dp[i-1][j]){
        return print_all_possible_lcs(a,b,i,j-1);
    }

    //if left and top both values are equal

    //then consider both

    vector<string> top = print_all_possible_lcs(a,b,i-1,j);
    vector<string> left = print_all_possible_lcs(a,b,i,j-1);

    top.insert(top.end(),left.begin(),left.end());
    return top;

}
int main(){
    string a,b;
    cin>>a>>b;
    lcs(a,b);
    vector<string>ans = print_all_possible_lcs(a,b,a.size(),b.size());
    for(string &s : ans)cout<<s<<endl;
}
