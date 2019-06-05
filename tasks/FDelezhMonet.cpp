#include <iostream>

#include "../library/lib.hpp"

class FDelezhMonet
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);
		ll x = read_ll();
		ll f = read_ll();

		ll ans = 0;

		forr(v, vec)
		{
			ll left = v - x;

			if(left > 0)
			{
				ll tr = x + f;
				ll steps = (left + tr - 1) / tr;
				ans += steps * f;
			}
		}

		print ans;
	}
};
