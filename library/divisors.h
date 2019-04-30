
static vll divisors(ll x)
{
	vll ans;

	for (ll i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			if(x / i == i)
			{
				ans.pb(i);
			}
			else
			{
				ans.pb(i);
				ans.pb(x / i);
			}
		}
	}

	sort(all(ans));

	return ans;
}
