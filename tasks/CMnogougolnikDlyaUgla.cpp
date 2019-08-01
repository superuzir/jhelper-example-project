#include <iostream>

#include "../library/lib.hpp"

class CMnogougolnikDlyaUgla
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll ang = read_ll();

			ll g = gcd(180, ang);

			ll n = 180 / g;
			ll k = ang / g;
			
			if(k > n - 2)
				n *= 2;
			
			print n;
		}
	}
};
