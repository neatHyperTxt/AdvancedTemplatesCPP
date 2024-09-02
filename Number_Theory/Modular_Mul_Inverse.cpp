ll binpowmod(ll a,ll b,ll m){
	ll res = 1;
	a%=m;
	if(a==0)return 0;
	while(b>0){
		if(b&1)
			res = (res * a)%m;
		a = (a * a)%m;
		b >>= 1;
	}
	return res%m;
}
ll gcd(ll a, ll b) {
	if(b==0)return a;
	return gcd(b,a%b);
}
ll modInverse(ll a,ll m){
	ll x = gcd(a,m);
	// A^m-1 ~= 1 MOD m;
	// multiply by A^-1 both sides
	// A^m-2 ~= A^-1 MOD m;
	// meaning if A power m-2 is divided by m, we will get A^-1 as the remainder
	if(x>=m)return -1;
	else return binpowmod(a,m-2,m);
}
