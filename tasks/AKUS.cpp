#include <iostream>

#include "../library/lib.hpp"

class AKUS
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll n = read_ll();

			if(n < 4)
				print 4 - n;
			else
				print n % 2;
		}
	}
};
