#include <iostream>

#include "../library/lib.hpp"
#include "../library/bit.h"
#include "../library/divisors.h"

class COperaciiNeImeyushieSmisla
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(i, q)
		{
			ll n = read_ll();

			if(((n + 1) & n) == 0)
			{
				auto d = divisors(n);
				print *(d.end() - 2);
			}
			else
			{
				print nextPowerOf2(n + 1) - 1;
			}
		}
	}
};
