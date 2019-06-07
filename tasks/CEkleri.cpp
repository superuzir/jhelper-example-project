#include <iostream>

#include "../library/lib.hpp"

class CEkleri
{
	pll check(ll n, ll k)
	{
		pll p;

		bool dec = true;

		while(n)
		{
			ll div = n / 10;

			if(dec || !div)
			{
				p.fi += min(n, k);
				n -= min(n, k);

				dec = false;
			}
			else
			{
				p.se += div;
				n -= div;
				dec = true;
			}
		}

		return p;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		ll l = 1;
		ll r = n;

		ll ans = max_ll;
		
		while(l <= r)
		{
			ll mid = l + (r - l) / 2;

			pll p = check(n, mid);
			
			if(p.fi < p.se)
			{
				l = mid + 1;
			}
			else
			{
				ans = min(ans, mid);
				r = mid - 1;
			}
		}
		
		print ans;
	}
};
