class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pa) {
        vector<int> g[n];
        for(auto p : pa){
            int u = p[1],v = p[0];
            g[u].push_back(v);
        }
        int indeg[n]={};
        for(int i=0;i<n;i++){
            for(int j : g[i])indeg[j]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<int> top_order;
        while(!q.empty()){
            int u = q.front();
            top_order.push_back(u);
            q.pop();
            for(auto j : g[u]){
                if(--indeg[j]==0)q.push(j);
            }
            n--;
        }
        vector<int> x;
        return n==0?top_order:x;
    }
};
