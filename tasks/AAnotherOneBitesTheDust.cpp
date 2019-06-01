#include <iostream>

#include "../library/lib.hpp"

class AAnotherOneBitesTheDust
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll a = read_ll();
		ll b = read_ll();
		ll c = read_ll();
			
		
		if(a == b)
			print a + b + 2 * c;
		else
			print 2 * c + 2 * min(a, b) + 1;
	}
};
