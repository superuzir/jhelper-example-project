#include <iostream>

#include "../library/lib.hpp"
#include "../library/primes.h"


class DProstoiGraf
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vll prv = primes(2*n);

		ll c = *lower_bound(all(prv), n) - n;
		
		print n + c;
		
		forn1(i, n)
		{
			print i, i + 1;
		}

		print n, 1;

		forn(i, c)
		{
			print i + 1, i + n/2 + 1;
		}
	}
};
