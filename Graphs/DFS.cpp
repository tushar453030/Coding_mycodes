    void dfs(int v,vector<int> adj[],vector<int>& bol,vector<int>& ans){
        bol[v]=true;
        ans.push_back(v);
        for(auto it:adj[v]){
            if(!bol[it]){
                dfs(it,adj,bol,ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bol(V,false);
        vector<int> ans;
        dfs(0,adj,bol,ans);
        return ans;
    }
