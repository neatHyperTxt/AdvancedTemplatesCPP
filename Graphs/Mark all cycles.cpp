vector<ll>vis(n,0);
	vector<ll>mark(n,false);
	auto dfs = [&](ll node,auto &&self)->void{
		vis[node] = 1;
		for(auto i:adj[node]){
			if(vis[i]==0)self(i,self);
			else if(vis[i]==1){
				ll cycleNode = i;
                do {
                    mark[cycleNode] = true;
                    cycleNode = v[cycleNode] - 1;
                } while (cycleNode != i);
			}
		}
		vis[node] = 2;
	}; 
	for(ll i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,dfs);
		}
	} 
