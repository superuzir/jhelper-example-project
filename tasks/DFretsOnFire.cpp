#include <iostream>

#include "../library/lib.hpp"

class DFretsOnFire
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		sort(all(vec));

		vll dif;

		forn1(i, n)
		{
			dif.pb(vec[i] - vec[i - 1]);
		}

		sort(all(dif));

		vll sum;

		sum.pb(0);

		forr(d, dif)
		{
			sum.pb(sum.back() + d);
		}

		ll q = read_ll();

		forn(_, q)
		{
			ll l = read_ll();
			ll len = read_ll() - l + 1;

			ll x = lower_bound(all(dif), len) - dif.begin();

			out << sum[x] + (dif.size() - x + 1) * len << " ";
		}
	}
};
