	void dfs(int i,vector<int> adj[],vector<bool>& vis,stack<int>& ele){
	    vis[i]=true;
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            dfs(it,adj,vis,ele);
	        }
	    }
	    ele.push(i);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V,false);
	    stack<int> ele;
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,ele);
	        }
	    }
	    while(!ele.empty()){
	        ans.push_back(ele.top());
	        ele.pop();
	    }
	    return ans;
	}
