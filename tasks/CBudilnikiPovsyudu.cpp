#include <iostream>

#include "../library/lib.hpp"

class CBudilnikiPovsyudu
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll x = read_vll(n);
		vll p = read_vll(m);

		ll x0 = x[0];

		forn(i, n)
			x[i] -= x0;

		ll nd = x[0];
		
		forn1(i, n)
			nd = gcd(min(nd, x[i]), max(nd, x[i]));

		forn(i, m)
		{
			if(nd % p[i] == 0)
			{
				print "YES";
				print x0, i + 1;
				return;
			}
		}

		print "NO";
	}
};
