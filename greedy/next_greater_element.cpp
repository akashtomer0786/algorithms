#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>a(n);
	    for(int i=0;i<n;i++)cin>>a[i];
	    
	    stack<int>s;
	    
	    vector<int>ans;
	    
	    for(int i=n-1;i>=0;i--){
	        
	        while(!s.empty() && a[i]>s.top())s.pop();
	        if(s.empty())ans.push_back(-1);
	        else ans.push_back(s.top());
	        s.push(a[i]);
	    }
	    reverse(ans.begin(),ans.end());
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	    
	    
	}
	return 0;
}
