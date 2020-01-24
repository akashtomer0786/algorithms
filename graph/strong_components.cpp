#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<set>
using namespace std;


vector<vector<int>>g, gr;
vector<bool>used;
vector<int>order, component;

void dfs1(int v) {
	used[v] = true;
	for (auto i : g[v]) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	order.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	component.push_back(v);
	for (int i : gr[v]) {
		if (!used[i]) {
			dfs2(i);
		}
	}
}
int main() {
	int n;
	cin >> n;
	//read graph
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	used.assign(n, false);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	used.assign(n, false);

	for (int i = 0; i < n; i++) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(v);
			//print component
			component.clear();
		}
	}
}
