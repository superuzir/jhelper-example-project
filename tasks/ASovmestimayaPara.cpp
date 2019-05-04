#include <iostream>

#include "../library/lib.hpp"

class ASovmestimayaPara
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll veca = read_vll(n);
		vll vecb = read_vll(m);


		{
			ll maxpr = min_ll;
			ll idx = 0;

			forn(i, n)
			forn(j, m)
			{
				if (ll pr = veca[i] * vecb[j]; pr > maxpr)
				{
					maxpr = pr;
					idx = i;
				}
			}

			veca.erase(veca.begin() + idx);
		}

		{
			ll maxpr = min_ll;

			forn(i, n - 1)
			forn(j, m)
			{
				if (ll pr = veca[i] * vecb[j]; pr > maxpr)
				{
					maxpr = pr;
				}
			}

			print maxpr;
		}
	}
};
