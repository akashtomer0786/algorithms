
#include<bits/stdc++.h>
#define N 20000
using namespace std;
vector<int> graph[N];
bool visited[N];
int best=0;
int bestvertex=0;
void dfs(int s,int d){
    visited[s]=true;
    if(d>best){
        best=d;
        bestvertex=s;
    }
    for( int i = 0 ; i < graph[s].size() ; i++  ){
        int temp = graph[s][i];
        if(!visited[temp]){
            dfs(temp,d+1);
        }
    }
}
int longest_path(int v){
   // memset(dist,0,sizeof(dist));
    memset(visited,false,sizeof(visited));

    dfs(0,0);
    int maxdis=0;
   // memset(dist,0,sizeof(dist));
    memset(visited,false,sizeof(visited));
    best=0;
    dfs(bestvertex,0);

    return best;

}
int main(){
    int n;
    cin>>n;

    for(int i = 0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    if(n==1)
        cout<<"0";
    else
        cout<<longest_path(n);

}
