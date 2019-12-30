
//const ll MOD = 998244353;
//const ll MOD = 1000000007;

static ll add(ll x, ll y) {
	x %= MOD; y %= MOD;
	return (x + y) % MOD;
}

static ll subtract(ll x, ll y) {
	x %= MOD; y %= MOD;
	return x >= y ? x - y : x - y + MOD;
}

static ll multiply(ll x, ll y) {
	x %= MOD; y %= MOD;
	return (x * y) % MOD;
}

static ll power(ll x, ll y) {
	x %= MOD;

	ll res = 1;

	while(y > 0) {
		if(y & 1) {
			res = multiply(res, x);
		}
		y = y / 2;
		x = multiply(x, x);
	}

	return res;
}

static ll divide(ll x, ll y) {
	return multiply(x, power(y, MOD - 2));
}
