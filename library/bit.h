static ll nextPowerOf2(ll n)
{
	ll count = 0;
	if (n && !(n & (n - 1))) return n;
	while(n) { n >>= 1ll; count++; }
	return 1ll << count;
}

static ll prevPowerOf2(ll n)
{
	for (ll i=n; i>=1; i--)
		if ((i & (i-1)) == 0)
			return i;
	return 0;
}

static ll popcnt(ll n)
{
	return __builtin_popcountll(n);
}
