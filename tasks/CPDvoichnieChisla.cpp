#include <iostream>

#include "../library/lib.hpp"
#include "../library/bit.h"


class CPDvoichnieChisla
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll p = read_ll();

		forn1(i, 1e9) {
			ll s = n - p * i;
			
			if(s < 1) {
				print -1;
				return;
			}
			
			if(i == popcnt(s) || 
				(i >= popcnt(s) && s >= i))
			{
				print i;
				return;
			}
		}
	}
};
