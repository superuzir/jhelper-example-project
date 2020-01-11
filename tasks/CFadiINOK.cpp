#include <iostream>

#include "../library/lib.hpp"
#include "../library/divisors.h"


class CFadiINOK
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll x = read_ll();

		auto d = divisors(x);
		ll n = d.size();

		pll ans;

		ll mn = max_ll;

		forn(i, n / 2 + 1){
			ll j = n - i - 1;

			if(lcm(d[i], d[j]) == x && max(d[i], d[j]) < mn)
			{
				mn = d[j];
				ans = {d[i], d[j]};
			}
		}

		print ans.fi, ans.se;
	}
};
