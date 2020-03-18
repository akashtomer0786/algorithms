#include<bits/stdc++.h>
using namespace std;
vector<int>g[10001];
vector<bool>visited(10001,false);
int cnt=0;
bool istree(int s,int parent){
    if(visited[s])return false;
    visited[s]=true;
    cnt++;
    for(int i=0;i<g[s].size();i++){
        if(g[s][i]!=parent){
            if(!istree(g[s][i],s))return false;
        }
    }
    return true;
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        for(int i=1;i<=e;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        if(istree(1,0) && cnt==n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
