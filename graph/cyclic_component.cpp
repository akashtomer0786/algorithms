#include<bits/stdc++.h>
using namespace std;
const int N = (int)2e5+10;
vector<int>g[N];
vector<bool>visited(N,false);
vector<int>comp;
vector<int>deg(N,0);
int dfs(int s){
    visited[s]=true;
    comp.push_back(s);
    for(int i=0;i<g[s].size();i++){
        int cur=g[s][i];
        if(!visited[cur]){
            dfs(cur);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int ans=0;
    for(int i=0;i<n+1;i++){
        if(!visited[i]){
            comp.clear();
            dfs(i);
            bool ok=true;
            for(int j : comp){
                if(deg[j]!=2)ok=false;
            }
            if(ok)ans++;
        }
    }
    cout<<ans<<endl;
}
