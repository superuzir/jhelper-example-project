#include <iostream>

#include "../library/lib.hpp"

class DRazdelenieMassiva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);

		vll dp(n + 1);

		nfor(i, n)
		{
			dp[i] = dp[i + 1] + vec[i];
		}

		multiset<pll> set;

		vector<multiset<pll>::iterator> its(n);

		for(ll i = k; i < n; i++)
		{
			its[i] = set.insert({dp[i], i});
		}

		ll maxi = n;

		ll ans = 0;

		nfor(i, k)
		{
			its[i] = set.insert({dp[i], i});
			
			auto top = *set.rbegin();
			
			for(ll j = top.se; j < maxi; j++)
			{
				set.erase(its[j]);
				ans += vec[j] * (i + 1);
			}

			maxi = top.se;
		}

		for(ll j = 0; j < maxi; j++)
		{
			ans += vec[j];
		}

		print ans;
	}
};
