#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>city(n);
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            city.push_back({a,b});
        }
        sort(city.begin(),city.end());

        ///sorted according to the first value

        ///find lis in the second value
        ///in this way we can ensure that a[i]>b[i] && a[j]>b[j]
        ///or a[i]<b[i] && a[j]<b[j]
        int lis[n];
        lis[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(city[i][1]>city[j][1])
                lis[i]=max(lis[i],lis[j]+1);
            }
            ans=max(ans,lis[i]);
        }
        cout<<ans<<endl;
    }
}
