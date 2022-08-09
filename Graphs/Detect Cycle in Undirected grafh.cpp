    bool dfs(int i,vector<int> adj[],vector<bool>& bol,int parent){
        bol[i]=true;
        for(auto it:adj[i]){
            if(!bol[it]){
                if(dfs(it,adj,bol,i)){
                    return true;
                }
            }
            else if(parent!=it){
                    return true;
                }
        }
        return false;
        
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> bol(V);
        for(int i=0;i<V;i++){
            if(!bol[i]){
                if(dfs(i,adj,bol,-1)) return true;
            }
        }
        return false;
    }
