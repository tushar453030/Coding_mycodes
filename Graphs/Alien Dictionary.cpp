    vector<int> toposort(int V, vector<int> adj[]) 
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
    string findOrder(string dict[], int N, int k) {
        //code here
        
        vector<int> adj[k];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.length(),s2.length());
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo= toposort(k,adj);
        string ans="";
        for(auto it:topo){
            ans=ans+char(it+'a');
        }
        return ans;
    }
