#include <iostream>

#include "../library/lib.hpp"
#include "../library/divisors.h"


class CNekoZanimaetsyaMatematikoi
{
public:
	void solve(std::istream &in, std::ostream &out)
	{
		ll a = read_ll();
		ll b = read_ll();

		if (a > b)
			swap(a, b);

		pll ans = {a * b / gcd(a, b), 0};

		forr(d, divisors(b - a))
		{
			ll k = (d - a % d) % d;
			ll lcm = (a + k) * (b + k) / gcd(a + k, b + k);

			ans = min(ans, {lcm, k});
		}

		print ans.se;
	}
};
