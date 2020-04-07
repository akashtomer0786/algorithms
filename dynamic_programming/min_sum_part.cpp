///minimum sum partition 
//https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
#include<bits/stdc++.h>
using namespace std;

int findmin(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++)
        dp[i][0]=true;

    for(int i=1;i<=sum;i++)
        dp[0][i]=false;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){


            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j]|dp[i-1][j-arr[i-1]];
            else dp[i][j] = dp[i-1][j];    
        }
    }

    int diff = INT_MAX;
    ///Sum of set1 is j and therefore sum of set2 is (totalSum-j) and therefore difference of sets is (totalSum-j) - (j) i.e. totalSum-2*j.
    for(int j=sum/2;j>=1;j--){
        if(dp[n][j]==true){
            diff=sum-2*j;
            break;
        }
    }
    return diff;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int ans = findmin(a,n);
        cout<<ans<<endl;
    }
}
