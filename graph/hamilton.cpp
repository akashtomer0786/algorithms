#include<bits/stdc++.h>
using namespace std;
vector<int>graph[500];
vector<bool>visited(500,false);
int cnt=1;
bool solve(int n,int v){
    if(cnt==n){
        return true;
    }
    for(int i : graph[v]){
        if(!visited[i]){
            visited[i]=true;
            cnt++;
            if(solve(n,i))return true;
            cnt--;
            visited[i]=false;
        }
    }
    return false;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    for(int i=0;i<m;i++){
	        int u,v;
	        cin>>u>>v;
	        graph[u].push_back(v);
	        graph[v].push_back(u);
	    }
	    
	    bool ans=false;
	    for(int i=1;i<=n;i++){
	        visited.assign(500,false);
	        visited[i]=true;
	        cnt=1;
    	    if(solve(n,i)){
    	        ans=true;
    	        break;
    	    }
	    }
	    if(ans)cout<<1<<endl;
	    else cout<<0<<endl;
	    
	    for(int i=0;i<100;i++){
	        graph[i].clear();
	        visited[i]=false;
	    }
	    
	}
	return 0;
}
