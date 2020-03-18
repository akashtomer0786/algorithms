class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int>todo;
                todo.push(i);
                color[i]=0;
                while(!todo.empty()){
                    int u = todo.front();
                    todo.pop();
                    for(int i=0;i<graph[u].size();i++){
                        int cur = graph[u][i];
                        if(color[cur]==-1){
                            color[cur]=color[u]^1;
                            todo.push(cur);
                        }else{
                            if(color[cur]==color[u])return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
