#include <iostream>

#include "../library/lib.hpp"

class CNekoZanimaetsyaMatematikoi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll a = read_ll();
		ll b = read_ll();

//		forn(k, 20)
//		{
//			print a + k, b + k, lcm(a + k, b + k);
//		}
		
		
		if(a > b)
		{
			ll c = a;
			a = b;
			b = c;
		}

		ll c = b % a;
		
		if(c == 0)
		{
			print 0;
		}
		else if(2 * a < b)
		{
			print b - 2 * a;
		}
		else 
		{
			if(b % c)
				print c - (b % c);
			else
				print 0;
		}
	}
};
