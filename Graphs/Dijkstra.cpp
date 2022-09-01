    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qq;
        vector<int> dis_to(V+1,INT_MAX);
        dis_to[S]=0;
        qq.push({0,S});
        while(!qq.empty()){
            int dist=qq.top().first;
            int prev=qq.top().second;
            qq.pop();
            for(auto it:adj[prev]){
                int nex=it[0];
                int nex_dist=it[1];
                if(dis_to[nex]>dis_to[prev]+nex_dist){
                    dis_to[nex]=dis_to[prev]+nex_dist;
                    qq.push({dis_to[nex],nex});
                }
            }
        }
        return dis_to;
    }
