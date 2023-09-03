struct item{
	int m,c;
};
 
struct segmentTree{
	int size;
	vector<item>seg;
	item NEUTRAL_ELEMENT = {INT_MAX,0};
	void init(int n){
		size = 1;
		while(size<n)size*=2;
		seg.resize(4*size);
	}
	item merge(item a,item b){
		if(a.m<b.m)return a;
		if(a.m>b.m)return b;
		return {a.m,a.c+b.c};
	}
	void build(vector<int>&a,int index,int lx,int rx){
		if(rx-lx==1){
			if(lx<(int)(a.size())){
				seg[index] = {a[lx],1};
			}
			return;
		}
		int mid = (lx+rx)/2;
		build(a,2*index+1,lx,mid);
		build(a,2*index+2,mid,rx);
		seg[index] = merge(seg[2*index+1],seg[2*index+2]);
	}
	void build(vector<int>&v){
		build(v,0,0,size);
	}
	void set(int i,int v,int index,int lx,int rx){
		if(rx-lx==1){
			seg[index] = {v,1};
			return;
		}
		int mid = (lx+rx)/2;
		if(i<mid)set(i,v,2*index+1,lx,mid);
		else set(i,v,2*index+2,mid,rx);
		seg[index] = merge(seg[2*index+1],seg[2*index+2]);
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	item mini(int l,int r,int index,int lx,int rx){
		if(lx>=l && rx<=r)return seg[index];
		if(rx<=l || lx>=r)return NEUTRAL_ELEMENT;
		int mid = (lx+rx)/2;
		item left = mini(l,r,2*index+1,lx,mid);
		item right = mini(l,r,2*index+2,mid,rx);
		return merge(left,right);
	}
	item mini(int l,int r){
		return mini(l,r,0,0,size);
	}
};
void solve()
{
	int n,m;
	cin>>n>>m;
	segmentTree st;
	st.init(n);
	vector<int>v(n);
	read(v);
	st.build(v);
	while(m--){
		int type;
		cin>>type;
		if(type==1){
			int index,val;
			cin>>index>>val;
			st.set(index,val);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<st.mini(l,r).m<<" "<<st.mini(l,r).c<<endl;
		}
	}
}
