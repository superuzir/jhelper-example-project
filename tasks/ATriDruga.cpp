#include <iostream>

#include "../library/lib.hpp"

class ATriDruga
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			vll a = read_vll(3);
			soa(a);

			print max(0ll, 2 * (a[2] - a[0] - 2));
		}
	}
};
