bool dfs(int src, vector<bool>&vis, vector<int>adj[], vector<bool>&rec)
{
    if(vis[src]==false)
  {     
    vis[src]=true;
    rec[src]=true;
    
      for(auto it:adj[src])
     {
         if(rec[it]==true)
          return true;
          
          if(!vis[it] && dfs(it,vis,adj,rec))
           return true;
     }
     
     rec[src]=false;
     return false;
  }
}

 bool isCyclic(int v, vector<int> adj[])
{
   vector<bool>vis(v,false);
   vector<bool>rec(v,false);
   
      for(int i=0;i<v;i++)
     {
        if(!vis[i] && dfs(i,vis,adj,rec))
        {
            // This will print your cycle elements
            
           /* for(int i=0;i<v;i++)
            {
                if(rec[i])
                 cout<<i<<" ";
            }*/
            
            return true;
        }
     }
     
   return false;
}
