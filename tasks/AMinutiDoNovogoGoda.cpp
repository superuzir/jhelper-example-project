#include <iostream>

#include "../library/lib.hpp"

class AMinutiDoNovogoGoda
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll h = read_ll();
			ll m = read_ll();

			print 24 * 60 - h * 60 - m;
		}
	}
};
