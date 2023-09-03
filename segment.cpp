#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define read(v)for(auto &i:v)cin>>i
#define pv(v)for(auto i:v)cout<<i<<" ";cout<<endl
using namespace std;

long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
// struct segmentTree{
// 	vector<unordered_set<ll>>seg;
// 	int size = 1;
// 	void init(int n){
// 		size = n;    
// 		seg.resize(4*size+5);
// 	}
// 	unordered_set<ll> merge(unordered_set<ll>s1,unordered_set<ll>s2){
// 		unordered_set<ll>final;
// 		for(auto i:s1)final.insert(i);
// 			for(auto i:s2)final.insert(i);
// 				return final;
// 		}
// 		void build(int index,int lx,int rx,vector<ll>&v){
// 			if(rx-lx==1){
// 				if(lx<v.size())seg[index].insert(v[lx]);
// 				return;
// 			}
// 			int mid = (lx+rx)/2;
// 			build(2*index+1,lx,mid,v);
// 			build(2*index+2,mid,rx,v);
// 			seg[index] = merge(seg[2*index+1],seg[2*index+2]);
// 		}
// 		void build(vector<ll>v){
// 			return build(0,0,size,v);
// 		}
// 		void update(int index,int i,int val,int lx,int rx){
// 			if(rx-lx==1){
// 				seg[index].erase(seg[index].begin(),seg[index].end());
// 				seg[index].insert(val);
// 				return;
// 			}
// 			int mid = (lx+(rx-lx)/2);
// 			if(i<mid){
// 				update(2*index+1,i,val,lx,mid);
// 			}
// 			else update(2*index+2,i,val,mid,rx);
// 			seg[index] = merge(seg[2*index+1],seg[2*index+2]);
// 		}
// 		void update(int i,int x){
// 			update(0,i,x,0,size);
// 		}
// 		ll query(int index,int lx,int rx,int l,int r){
// 			if(lx>=l && rx<=r)return seg[index].size();
// 			if(lx>=r || rx<=l)return 0;
// 			int mid = (lx+rx)/2;
// 			ll left = query(2*index+1,lx,mid,l,r);
// 			ll right = query(2*index+2,mid,rx,l,r);
// 			return (left+right);
// 		}
// 		ll query(int l,int r){
// 			return query(0,0,size,l,r);
// 		}
// 	};
vector<int> sieve(200005,1);
void createSieve(){
	for(int i=2;i*i<sieve.size();i++){
		if(sieve[i]==1){
			for(int j=i*i;j<sieve.size();j+=i){
				sieve[j] = i;
			}
		} 
	}
}
// int findPar(int node,vector<int>&parent){
// 	if(node==parent[node])return node;
// 	return parent[node] = findPar(parent[node],parent);
// }
// void unite(int x,int y,vector<int>&parent,vector<int>&size){
// 	x = findPar(x,parent);
// 	y = findPar(y,parent);
// 	if(x==y)return;
// 	if(size[x]<size[y]){
// 		size[y]+=size[x];
// 		parent[x] = y;
// 	}
// 	else{
// 		size[x]+=size[y];
// 		parent[y] = x;
// 	}
// }
// bool isPossible(vector<ll>v,ll x,ll k){
// 	ll count = 1;
// 	ll last = v[0];
// 	for(int i=1;i<v.size();i++){
// 		if(v[i]-last>=x){
// 			count++;
// 			last = v[i];
// 		}
// 	}
// 	return count>=k;
// }
ll calc(vector<ll>v){
	ll n = v.size(),sum = 0;
	ll maxi = 0;
	for(ll i=0;i<n;i++){
		sum+=((i+1)*v[i]);
		if((i+1)*v[i]>maxi)maxi = (i+1)*v[i];
	}
	return sum-maxi;
}
bool isPossible(ll a,ll b,ll c){
	return b*c<=a;
}
// ll calc(ll m,ll mid,ll k,ll a1){

// }

map<int,vector<int>>mp;
void solve()
{
	ll x;
	cin>>x;
	vector<int>ans;
	ans.push_back(x);
	if(x&1){
		x--;
		ans.push_back(x);
	}
	while(true){
		if(x==2)break;
		// calc max power of 2 you can subtract from current x as a divisor;
		int raise = 1;
		while(x%(2*raise)==0){
			raise*=2;
		}
		if(raise==x)raise/=2; // if maximum power of 2 that can be subtracted is exactly equal to x, then it will make it 0, thus substract the half of this maximum power of 2
		x-=raise;
		ans.push_back(x);
	}
	ans.push_back(1);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
		cout<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("Error.txt","w",stderr);
	freopen("output.txt","w",stdout);
	#endif 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0; 
}