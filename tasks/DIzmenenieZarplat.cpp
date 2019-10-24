#include <iostream>

#include "../library/lib.hpp"

class DIzmenenieZarplat
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			ll s = read_ll();
			auto vec = read_vpll(n);
			
			sort(all(vec));

			forn(i, n / 2)
				s -= vec[i].fi;
			
			print s;
		}
	}
};
