#include <iostream>

#include "../library/lib.hpp"

class CPryatki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vll vec = read_vll(k);

		vll cnt(10e6, 0);

		set<pll> exclude;

		forr(v, vec)
		{
			if(cnt[v - 1]) exclude.insert({v - 1, v});
			if(cnt[v + 1]) exclude.insert({v + 1, v});

			exclude.insert({v, v});

			cnt[v]++;
		}

		print 3 * n - 2 - exclude.size();
	}
};
