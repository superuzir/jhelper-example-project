#include <iostream>

#include "../library/lib.hpp"

class DStasIOcheredVBufet
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vpll vec;
		
		forn(i, n)
		{
			pll ab;
			ab.fi = read_ll();
			ab.se = read_ll();
			vec.pb(ab);
		}
		
		print vec;
	}
};
