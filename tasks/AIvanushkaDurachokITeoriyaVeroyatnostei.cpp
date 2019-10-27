#include <iostream>

#include "../library/lib.hpp"

class AIvanushkaDurachokITeoriyaVeroyatnostei
{
public:
	ll getInt(ll n) const
	{
		if(n == 1)
			return 1;

		ll p[2] = {1, 2};

		forlr(i, 2, n)
		{
			ll cur = (p[0] + p[1]) % MOD;
			p[0] = p[1];
			p[1] = cur;
		}

		return p[1];
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		ll ans = getInt(n) * 2 % MOD;

		ans += getInt(m) * 2;
		ans += MOD - 2;
		ans %= MOD;

		print ans;
	}
};
