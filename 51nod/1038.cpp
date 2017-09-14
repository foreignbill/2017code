inline ll qm(ll a,ll n,ll p){
	if(!n) return 1;
	ll ret=qm(a,n/2,p);
	ret=ret*ret%p;
	if(n&1) return ret*a%p;
	return ret;
}
inline bool pan_g(ll g, ll p) {
	for (int i = 0; i < c.size(); ++i)
		if (qm(g, c[i], p) == 1)
			return 0;
	return 1;
}
inline ll findg(ll p) {
	c.clear();
	ll tmp = p - 1;
	ll k = 2;
	while (k * k <= tmp) {
		if (tmp % k == 0) {
			c.push_back(k);
			while (tmp % k == 0)
			tmp /= k;
		}
		++k;
	}
	if (tmp != 1)
		c.push_back(tmp);
	for (int i = 0; i < c.size(); ++i)
		c[i] = (p-1) / c[i];
	ll g = 1;
	while (true) {
		if (pan_g(g, p)) {
			return g;
		}
		++g;
	}
	return 0;
}
