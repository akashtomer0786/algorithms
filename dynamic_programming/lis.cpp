#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>a(n);
	    for(int i=0;i<n;i++)cin>>a[i];
	    int ans=1;
	    int lis[n+1];
	    lis[0]=1;
	    for(int i=1;i<n;i++){
	        int prevmax=0;
	        for(int j=0;j<i;j++){
	            if(lis[j]>prevmax && a[i]>a[j]){
	                prevmax=lis[j];
	            }
	        }
	        lis[i]=prevmax+1;
	        ans=max(ans,lis[i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
