#include <iostream>

#include "../library/lib.hpp"

class COsadaValgalli
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll q = read_ll();
		vll veca = read_vll(n);
		vll veck = read_vll(q);

		vll health(n);

		health[0] = veca[0];

		forn1(i, n)
		{
			health[i] = health[i - 1] + veca[i];
		}

		ll damage = 0;

		forn(i, q)
		{
			damage += veck[i];
			auto it = lower_bound(all(health), damage);
			if(it == health.end())
			{
				damage = 0;
				print n;
			}
			else
			{
				if(*it == damage)
					++it;
				
				ll left = health.end() - it;
				
				if(left == 0)
				{
					damage = 0;
					print n;
				}
				else
				{
					print left;
				}
			}
		}
	}
};
