class segTree{
	vector<ll>seg;
	vector<ll>lazy;
	ll size;
public:
	ll merge(ll &a,ll &b){
		return a+b;
	}
	segTree(ll n){
		size = 1;
		while(size<n)size*=2;
		seg.resize(size*2,0);
		lazy.resize(size*2,0);
	}
	void build(ll index,ll lx,ll rx,vector<ll>&a){
		if(rx-lx==1){
			if(lx<a.size())seg[index] = a[lx];
			return;
		}
		ll mid = (lx+rx)/2;
		build(2*index+1,lx,mid,a);
		build(2*index+2,mid,rx,a);
		seg[index] = merge(seg[2*index+1],seg[2*index+2]);
	}
	void build(vector<ll>&a){
		return build(0,0,size,a);
	}
	ll query(ll index,ll lx,ll rx,ll l,ll r){
		if(lx>=l && rx<=r)return seg[index];
		if(rx<=l || lx>=r)return 0;
		ll mid = (lx+rx)/2;
		ll left = query(2*index+1,lx,mid,l,r);
		ll right = query(2*index+2,mid,rx,l,r);
		return merge(left,right);
	}
	ll query(ll l,ll r){
		return query(0,0,size,l,r);
	}
	void update(ll index,ll lx,ll rx,ll idx,ll val){
		if(rx-lx==1){
			seg[index] = val;
			return;
		}
		ll mid = (lx+rx)/2;
		if(idx<mid)update(2*index+1,lx,mid,idx,val);
		else update(2*index+2,mid,rx,idx,val);
		seg[index] = merge(seg[2*index+1],seg[2*index+2]);
	}
	void update(ll idx,ll val){
		return update(0,0,size,idx,val);
	}
	void rangeUpdate(ll index,ll lx,ll rx,ll l,ll r,ll val){
		if(lazy[index]!=0){
			seg[index]+=(rx-lx)*lazy[index];
			if(rx-lx!=1){
				lazy[2*index+1] += lazy[index];
				lazy[2*index+2] += lazy[index];
			}
			lazy[index] = 0;
		}
		if(rx<=l || lx>=r) return;
		if(lx>=l && rx<=r){
			seg[index] += (rx-lx)*val;
			if(rx-lx!=1){
				lazy[2*index+1] += val;
				lazy[2*index+2] += val;
			}
			return;
		}
		ll mid = (lx+rx)/2;
		rangeUpdate(2*index+1,lx,mid,l,r,val);
		rangeUpdate(2*index+2,mid,rx,l,r,val);
		seg[index] = merge(seg[2*index+1],seg[2*index+2]);
	}
	void rangeUpdate(ll l,ll r,ll val){
		return rangeUpdate(0,0,size,l,r,val);
	}
	ll rangeQuery(ll index,ll lx,ll rx,ll l,ll r){
		if(lazy[index]!=0){
			seg[index] += (rx-lx)*lazy[index];
			if(rx-lx!=1){
				lazy[2*index+1] += lazy[index];
				lazy[2*index+2] += lazy[index];
			}
			lazy[index] = 0;
		}
		if(rx<=l || lx>=r)return 0;
		if(lx>=l && rx<=r)return seg[index];
		ll mid = (lx+rx)/2;
		ll left = rangeQuery(2*index+1,lx,mid,l,r);
		ll right = rangeQuery(2*index+2,mid,rx,l,r);
		return merge(left,right);
	}
	ll rangeQuery(ll l,ll r){
		return rangeQuery(0,0,size,l,r);
	}
};
