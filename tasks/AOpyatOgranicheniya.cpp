#include <iostream>

#include "../library/lib.hpp"

class AOpyatOgranicheniya
{
	struct Restr
	{
		ll l;
		ll r;
		ll hmax;
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll h = read_ll();
		ll m = read_ll();

		vll hmax(n, h);

		forn(i, m)
		{
			ll l = read_ll();
			ll r = read_ll();
			ll hi = read_ll();

			for(ll x = l; x <= r; ++x)
			{
				hmax[x - 1] = min(hi, hmax[x - 1]);
			}
		}

		ll ans = 0;

		forr(hm, hmax)
		{
			ans += hm * hm;
		}

		print ans;
	}
};
