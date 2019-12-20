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
		
		if(p == 0)
		{
			print popcnt(n);
			return;
		}
		
		ll ans = 0;
		
		while(1){
			if(n < 0)
			{
				print -1;
				return;
			}
			
			if(ans >= popcnt(n) && ans <= n)
			{
				print ans;
				return;
			}
			
			ans++;
			n -= p;
		}
	}
};
