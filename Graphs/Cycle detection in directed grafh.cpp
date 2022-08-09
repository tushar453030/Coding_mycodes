    bool dfs(int i,vector<int> adj[],vector<bool>& vis,vector<bool>& sta){
        vis[i]=true;
        sta[i]=true;
        for(auto it: adj[i]){
            if(!vis[it]){
                if(dfs(it,adj,vis,sta)) return true;
            }
            else if(sta[it]){
                return true;
            }
        }
        sta[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> sta(V,false);
        for(int i=0;i<V;i++){
            if(dfs(i,adj,vis,sta)){
                return true;
            }
        }
        return false;
    }
