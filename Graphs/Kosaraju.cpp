class Kosaraju{
	bool * vis;
	vector<vector<int>>transpose,adj;
	int V;
public:
	Kosaraju(int V,vector<vector<int>>adj){
		transpose.resize(V);
		this->V = V;
		this->adj = adj;
		for(int i=0;i<V;i++){
			for(auto j:adj[i]){
				transpose[j].push_back(i);
			}
		}
	}
	void dfs_topo(int node,stack<int>&s){
	    vis[node] = true;
	    for(auto i:adj[node]){
	        if(!vis[i]){
	            dfs_topo(i,s);
	        }
	    }
	    s.push(node);
	}
	void dfs(int node){
	    vis[node] = true;
	    for(auto i:transpose[node]){
	        if(!vis[i]){
	            dfs(i);
	        }
	    }
	}
	int components(){
		stack<int>s;
        vector<vector<int>>transpose(V);
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                transpose[j].push_back(i);
            }
        }
        vis = new bool[V];
        for(int i=0;i<V;i++)vis[i] = false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs_topo(i,s);
            }
        }
        for(int i=0;i<V;i++)vis[i] = false;
        int count = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!vis[node]){
                count++;
                dfs(node);
            }
        }
        return count;
	}
};
