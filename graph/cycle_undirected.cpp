#include<iostream>
#include<algorithm>
#pragma warning(disable : 4996)
#include<vector>
using namespace std;
#include<map>
//using namespace std;

vector<bool>visited;
bool dfs(vector<int> g[], int parent, int s) {
    visited[s] = true;
   // if (parent == s)return true; //for self edge

    for (int i = 0; i < g[s].size(); i++) {
        int cur = g[s][i];
        if (!visited[cur]) {
            if (dfs(g, s, cur))return true;
        }
        else {
            if (cur != parent)return true;
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
    // Your code here
    visited.resize(V);
    visited.assign(V,false);
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            if (dfs(g, -1, i))return true;
        }
    }
    return false;

}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int>g[n];
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        if (isCyclic(g, n)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
        visited.clear();
    }
}
