#include <iostream>

#include "../library/lib.hpp"
#include "../library/divisors.h"


class DPochtiVseDeliteli
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(i, q)
		{
			ll n = read_ll();

			vll v = read_vll(n);

			sort(all(v));

			ll ans = v.front() * v.back();

			v.pb(1);
			v.pb(ans);

			sort(all(v));

			auto d = divisors(ans);
			
			if(d == v)
				print ans;
			else
				print -1;
		}
	}
};
