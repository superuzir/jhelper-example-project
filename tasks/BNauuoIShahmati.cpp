#include <iostream>

#include "../library/lib.hpp"

class BNauuoIShahmati
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		forn(m, 100000)
		{
			if(2*(m - 1) + 1 >= n)
			{
				print m;
				
				ll m1 = m;

				for(ll c = 1; c <= m && n; c++, n--)
				{
					print 1, c;
				}

				for(ll c = 2; c <= m && n; c++, n--)
				{
					print c, m;
				}

				return;
			}
		}
	}
};
