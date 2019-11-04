#include <iostream>

#include "../library/lib.hpp"

class AOplataBezSdachi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll a = read_ll();
			ll b = read_ll();
			ll n = read_ll();
			ll s = read_ll();

			ll s1 = min(s / n, a) * n;

			if(s - s1 <= b)
				print "YES";
			else
				print "NO";
		}
	}
};
