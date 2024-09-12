class EulerCycle{
public:
	ll n;
	vector<ll>indegree;
	vector<set<ll>> adjj;
	EulerCycle(ll n, vector<vector<ll>>&adj){
		this->n = n;
		adjj.resize(n);
		indegree.resize(n);
		for(ll i=0;i<n;i++){
			for(auto j:adj[i]){
				indegree[j]++;
				adjj[i].insert(j);
			}
		}
	}
	void dfs(ll node,vector<ll>&ans) {
        while (!adjj[node].empty()) {
            ll to = *adjj[node].begin(); 
            adjj[node].erase(to); 
            adjj[to].erase(node); 
            dfs(to,ans); 
        }
        ans.push_back(node);
    }
	vector<ll> cycle_path(ll source){
		for(ll i=0;i<n;i++)if(indegree[i]&1)return {};
		vector<ll>ans;
		dfs(source,ans);
		return ans;
	}
};
