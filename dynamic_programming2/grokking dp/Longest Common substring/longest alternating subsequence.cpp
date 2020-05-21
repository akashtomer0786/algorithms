#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int longest_alternating(int n){
    int dp[n][2];
    /// dp[i][0] length of longest alternating
    ///sequence sub sequence at index i  and
    ///last element is greater
    ///than its previous element
    /// dp[i][1] length of longest alternating
    ///subsequence ending at index i and last
    /// element is smaller
    ///than its previous element
    for(int i=0;i<n;i++){
        dp[i][0]=1;
        dp[i][1]=1;
    }

    int res=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[j] < a[i] && dp[i][0] < dp[j][1] + 1)
                dp[i][0] = dp[j][1] + 1;

            // If arr[i] is smaller, then check with las[j][0]
            if( a[j] > a[i] && dp[i][1] < dp[j][0] + 1)
                dp[i][1] = dp[j][0] + 1;
        }
        if (res < max(dp[i][0], dp[i][1]))
            res = max(dp[i][0], dp[i][1]);
    }

    return res;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        for(int &i : a)cin>>i;
        for(int i : a){
            cout<<i<<endl;
        }
        cout<<longest_alternating(n)<<endl;
    }
}
