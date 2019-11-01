
static ll fibMod(ll f0, ll f1, ll n, ll mod) {
	if(n == 1) return f0 % mod;

	forlr(i, 2, n) {
		ll t = f1;
		f1 = f1 + f0;
		f0 = t;

		f0 %= mod;
		f1 %= mod;
	}

	return f1 % mod;
}
