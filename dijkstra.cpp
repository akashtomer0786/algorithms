#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
 
void dijkstra(vector<int> &d, vector<int> &path,vector<vector<pair<int,int>>> const &graph,int s,int n) {
 
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ s,0 });
	for (int i = 0; i < n; i++)
		d[i] = INT_MAX, path[i] = 0;
	d[s] = 0;
	while (!pq.empty()) {
		int v = pq.top().second;
		int dis_v = pq.top().first;
		pq.pop();
 
		for (auto edge : graph[v]) {
			int to = edge.first;
			int len = edge.second;
 
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				path[to] = v;
				pq.push({ d[to],to });
			}
		}
	}
}
void addEdge(vector<vector<pair<int,int>>> &g,int u,int v,int len) {
	g[u].push_back({ v,len });
	g[v].push_back({ u,len });
 
}
int main() {
	vector<vector<pair<int, int>>> g(9);
	addEdge(g,0, 1, 4);
	addEdge(g,0, 7, 8);
	addEdge(g,1, 2, 8);
	addEdge(g,1, 7, 11);
	addEdge(g,2, 3, 7);
	addEdge(g,2, 8, 2);
	addEdge(g,2, 5, 4);
	addEdge(g,3, 4, 9);
	addEdge(g,3, 5, 14);
	addEdge(g,4, 5, 10);
	addEdge(g,5, 6, 2);
	addEdge(g,6, 7, 1);
	addEdge(g,6, 8, 6);
	addEdge(g,7, 8, 7);
	vector<int> p(9), d(9);
	dijkstra(d, p, g, 0, 9);
	for (int i = 0; i < 9; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	for (int j = 0; j < 9; j++) {
		cout << p[j] << " ";
	}
}
