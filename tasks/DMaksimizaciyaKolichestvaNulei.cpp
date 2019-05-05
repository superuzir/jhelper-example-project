#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class DMaksimizaciyaKolichestvaNulei
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll a = read_vll(n);
		vll b = read_vll(n);

		vpll c;

		ll zero  = 0;
		
		forn(i, n)
		{
			if(a[i] != 0)
			{
				pll p {a[i], b[i]};
				ll g = gcd(p.fi, p.se);

				p.fi /= g;
				p.se /= g;

				if(p.fi < 0)
				{
					p.fi *= -1;
					p.se *= -1;
				}

				c.pb(p);
			}
			else if(a[i] == 0 && b[i] == 0)
				zero++;
		}

		sort(all(c));

		ll ans = 0;

		itersame(all(c), [&](auto b, auto e){
			ans = max(ans, ll(e - b));
		});

		print ans + zero;
	}
};
