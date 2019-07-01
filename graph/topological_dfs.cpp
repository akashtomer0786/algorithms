    class Solution {
    public:
        vector<int> findOrder(int n, vector<vector<int>>& pa) {
            vector<int> g[n];
            for(auto p : pa){
                int u = p[1],v = p[0];
                g[u].push_back(v);
            }
            vector<bool>visited(n,false);
            vector<bool>instack(n,false);
            vector<int>order;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    if(!dfs(i,visited,instack,g,order))return {};
                }
            }
            reverse(order.begin(),order.end());
            return order;




        }


        bool dfs(int x,vector<bool> &visited,vector<bool> &instack,vector<int> g[],vector<int>&order){
            instack[x]=true;
            visited[x]=true;
            for(int i=0;i<g[x].size();i++){
                if(instack[g[x][i]]==true)return false;
                else if(!visited[g[x][i]] && !dfs(g[x][i],visited,instack,g,order))return false;
            }
            instack[x]=false;
            order.push_back(x);
            return true;
        }

    };
