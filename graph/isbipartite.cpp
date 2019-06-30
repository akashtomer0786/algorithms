class Solution {
public:
    int color[100];
    vector<int> g[100];
        bool dfs(int x,int col){
       // if(color[x]!=-1)
         //   return color[x]==col;
        color[x]=col;
        int ans = 1;
        for(int i : g[x]){
            if(color[i]==-1)
                if(!dfs(i,col^1))return false;
            if(color[i]==col)return false;
            

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& pa) {
        int n = pa.size();
        memset(color,-1,sizeof(color));
        for(int i=0;i<pa.size();i++){
            for(int j :pa[i]){
            int u = i,v = j;
            g[u].push_back(v);
            //g[v].push_back(u);
            }
        }
        if(!dfs(0,1))return false;
        for(int i=1;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,color[i-1]^1))return false;
            }
        }

        return true;


    }


};
