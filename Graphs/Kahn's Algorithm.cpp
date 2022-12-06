	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    // kahn's algorithm
	    // This algorithm is finding the topological sort using BFS 
	    // To use BFS we use two things indegrees and a queue
	    
	    vector<int> indegree(V,0);     
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> qq;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            qq.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    while(!qq.empty()){
	        int node=qq.front();
	        qq.pop();
	        topo.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) qq.push(it);
	        }
	    }
	    return topo;
	}
