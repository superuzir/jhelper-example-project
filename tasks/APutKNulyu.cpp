#include <iostream>

#include "../library/lib.hpp"

class APutKNulyu
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(i, t)
		{
			ll n = read_ll();
			ll k = read_ll();

			ll ans = 0;

			while(n)
			{
				ll ost = n % k; 
				
				if (ost == 0)
				{
					n /= k;
					ans++;
				}
				else
				{
					n -= ost;
					ans += ost;
				}
			}

			print ans;
		}
	}
};
