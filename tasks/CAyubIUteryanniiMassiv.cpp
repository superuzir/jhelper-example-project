#include <iostream>

#include "../library/lib.hpp"

class CAyubIUteryanniiMassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll l = read_ll();
		ll r = read_ll();
		
		if(l == r)
		{
			print (l * n) % 3 == 0;
		}
		
		
	}
};
