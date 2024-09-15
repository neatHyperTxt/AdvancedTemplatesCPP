vector<ll>adj[mxN];
class BinaryLifting {
	vector<vector<ll>> up;
	ll log = 20;
	vector<ll>heights;
	public:
	BinaryLifting(ll n,vector<ll>&parent){
		up.resize(n,vector<ll>(log,-1));
		heights.resize(n,0);
		for(ll i=0;i<n;i++)up[i][0] = parent[i];
		for(ll j=1;j<log;j++){
			for(ll i=0;i<n;i++){
				if(up[i][j-1]!=-1)
					up[i][j] = up[up[i][j-1]][j-1];
			}
		}
		dfs(0,0);
	} 
	void dfs(ll node,ll h){
		heights[node] = h;
		for(auto i:adj[node]){
			dfs(i,h+1);		
		}
	}
	void print(){
		pv(heights);
	}
	ll kthAncestor(ll node,ll k){
		for(ll j=0;j<log;j++){
			if((1<<j)&k){
				node = up[node][j];
				if(node==-1)break;
			}
		}
		return node;
	}
	ll LCA(ll u, ll v){
		if(heights[u]>heights[v])swap(u,v);
		ll diff = heights[v]-heights[u];
		v = kthAncestor(v,diff);
		if(u==v)return u;
		for(ll i=19;i>=0;i--){
			if(up[u][i] != up[v][i]){
				u = up[u][i];
				v = up[v][i];
			}
		}
		return kthAncestor(u,1);
	}
};
