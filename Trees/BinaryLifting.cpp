class BinaryLifting{
	// assuming 1 based indexing throughout to take care of ancestor out of bound case with 0
	private:
		vector<vector<ll>>dp;
		vector<vector<ll>>adj; 
		vector<ll>depth;
		ll LOG;
	public:
		BinaryLifting(ll n,vector<vector<ll>>&adj){
			ll LOG = log2(n) + 1; 
			this->LOG = LOG;
			this->adj = adj;
			dp.resize(n+1,vector<ll>(LOG,0));
			depth.resize(n+1,0);
			form(n);
		}
		void findFirstParents(ll node,ll par){
			dp[node][0] = par;
			depth[node] = depth[par] + 1;
			for(auto i:adj[node]){
				if(i!=par)findFirstParents(i,node);
			}
		}
		void form(ll n){
			findFirstParents(1,0);
			for(ll i=1;i<LOG;i++){
				for(ll node=1;node<=n;node++){
					dp[node][i] = dp[dp[node][i-1]][i-1];
				}
			}
		}
		ll findAncestor(ll node,ll k){
			if(k>depth[node])return 0;
			for(ll i=LOG;i>=0;i--){
				if(k&(1<<i)){
					node = dp[node][i];
				}
			}
			return node;
		};
		ll findLCA(ll u,ll v){
			if(depth[u] > depth[v])swap(u,v); 
			v = findAncestor(v,depth[v]-depth[u]); 
			if(u==v)return u;
			for(ll i=LOG-1;i>=0;i--){
				if(dp[u][i] != dp[v][i]){
					u = dp[u][i];
					v = dp[v][i];
				}
			}
			return dp[u][0];
		}
};
