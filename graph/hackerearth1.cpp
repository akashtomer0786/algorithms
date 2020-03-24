//https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int eps=1e-9;
queue <int> t;
double in[N],out[N];
double val[N];
vector <int> adj[N];
void topological_sort(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
			t.push(i);
		}
	}
	while(!t.empty())
	{
		int u=t.front();
		t.pop();
 
		for(auto i:adj[u])
		{
			in[i]-=1;
			val[i]+=val[u]/out[u];
			if(in[i]==0)
			{
				t.push(i);
			}
		}
	}
}
int main(){
    int n,m,cur;
    cin>>n>>m>>cur;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        in[v]++;
        out[u]+=1.0;
    }
    val[cur]=1;
    topological_sort(n);
    double maxx = -1.0;
    for(int i=1;i<=n;i++){
        if(!out[i])
        maxx=max(maxx,val[i]);
    }
    for(int i=1;i<=n;i++){
        if(!out[i] and abs(val[i]-maxx)<=eps){
            cout<<i<<" ";
        }
    }
 
}
