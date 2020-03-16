class Solution {
public:
   bool canFinish(int numCourses, vector<vector<int>>& pa){
        int n = numCourses;
        vector<int> g[n];
        for(auto p : pa){
            int u = p[1],v=p[0];
            g[u].push_back(v);
        }
        int indeg[n]={};
        for(int i=0;i<n;i++){
            for(auto j : g[i])
                indeg[j]++;
        }
       queue<int> q;
       for(int i=0;i<n;i++){
           if(indeg[i]==0)q.push(i);
       }
       while(!q.empty()){
           int u = q.front();
           q.pop();
           for(int v: g[u]){
               if(--indeg[v]==0)q.push(v);
           }
           n--;
       }
       return n==0;

    }
};
