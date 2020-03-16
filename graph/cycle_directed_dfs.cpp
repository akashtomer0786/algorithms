class Solution {
public:
    bool dfs(vector<int>g[],int n,vector<int>&todo,vector<int>&done,int node){
        if(todo[node])return false; //there is a cycle
        if(done[node])return true; //already visited
        
        done[node]=true;
        todo[node]=true;
        for(int i=0;i<g[node].size();i++){
           // if(done[])
            if(dfs(g,n,todo,done,g[node][i])==false)return false;
        }
        todo[node]=false;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>g[n];
        vector<int>todo(n,false),done(n,false);
        for(int i=0;i<pre.size();i++){
            g[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<n;i++){
            if(done[i])continue;
            if(dfs(g,n,todo,done,i)==false)return false;
        }
        return true;
    }
};
