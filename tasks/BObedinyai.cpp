#include <iostream>

#include "../library/lib.hpp"

class BObedinyai
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();
		
		forn(i, t)
		{
			ll n = read_ll();
			vll vec = read_vll(n);
			
			forr(v, vec)
			{
				v = v % 3;
			}
			
			ll c0 = count(all(vec), 0); 
			ll c1 = count(all(vec), 1); 
			ll c2 = count(all(vec), 2); 
			
//			print vec, c0, c1, c2;
			
			ll g = min(c1, c2);
			c1 -= g;
			c2 -= g;
			
			print c0 + g + c1 / 3 + c2 / 3; 
		}
	}
};
