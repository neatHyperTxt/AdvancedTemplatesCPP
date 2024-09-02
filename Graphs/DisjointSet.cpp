struct DisjoinSet{
	vector<int>rank,parent,size;
public:
	DisjoinSet(int n){
		rank.resize(n+1,0);
		parent.resize(n+1);
		size.resize(n+1,1);
		for(int i=0;i<=n;i++)parent[i] = i;
	}
	int findPar(int node){
		if(node==parent[node])return node;
		return parent[node] = findPar(parent[node]);
	}
	void unite_by_rank(int a,int b){
		a = findPar(a);
		b = findPar(b);
		if(a==b)return;
		if(rank[a]<rank[b]){
			parent[a] = b;
		}
		else if(rank[b]<rank[a]){
			parent[b] = a;
		}
		else{
			parent[a] = b;
			rank[a]++;
		}
		return;
	}
	void unite_by_size(int a,int b){
		a = findPar(a);
		b = findPar(b);
		if(a==b)return;
		if(size[a]<size[b]){
			size[b]+=size[a];
			parent[a] = b;
		}
		else{
			size[a]+=size[b];
			parent[b] = a;
		}
		return;
	}
};
