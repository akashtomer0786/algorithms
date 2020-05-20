
#include<bits/stdc++.h>
using namespace std;
///using lcs
int min_deletions(string s,string s1){
    int n = s.size();

    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)dp[i][j]=0;
            else {
                if(s[i-1]==s1[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    return n-dp[n][n];
}
///using pure dp
int min_deletions1(string s){
    int n = s.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1];
            }else{
                dp[i][j]=min(2+dp[i+1][j-1],min(1+dp[i+1][j],1+dp[i][j-1]));
            }
        }
    }
    return dp[0][n-1];
}
///another can be length - longest common subsequence

///now a beautiful one
bool ispalindrome(string s){
    int left=0;
    int right=s.size()-1;
    while(left<right){
        if(s[left]!=s[right])return false;
        left++;
        right--;
    }
    return true;;
}
int bfs(string s){
    queue<string>q;
    q.push(s);
    int deletions=0;
    while(!q.empty()){
            int sz=q.size();
    while(sz--){
        string cur = q.front();
        q.pop();
        if(ispalindrome(cur))return deletions;
        /// i tried to delete element from different positions
        for(int i=0;i<cur.size();i++){
            string next_s = cur.substr(0,i) + cur.substr(i+1);
            q.push(next_s);
        }
        }
        deletions++;
    }
    return deletions;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        cout<<bfs(s)<<endl;
    }
}
