
static ll fib(ll f0, ll f1, ll n) {
	if(n == 1) return f0;

	forlr(i, 2, n) {
		ll t = f1;
		f1 = f1 + f0;
		f0 = t;
	}

	return f1;
}
