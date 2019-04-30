
static vll factorize(ll x)
{
	vll ans;

	for (ll i = 2; i * i <= x; i++)
	{
		while (x % i == 0)
		{
			ans.pb(i);
			x /= i;
		}
	}

	if (x != 1)
		ans.pb(x);

	return ans;
}
