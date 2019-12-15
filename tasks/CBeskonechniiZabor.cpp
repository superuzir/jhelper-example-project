#include <iostream>

#include "../library/lib.hpp"

class CBeskonechniiZabor
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			ll a = read_ll();
			ll b = read_ll();
			ll k = read_ll();

			if(a < b) swap(a, b);

			ll g = gcd(a, b);

			a /= g;
			b /= g;

			ll c = a - 1;

			print c / b + (c % b != 0) >= k ? "REBEL" : "OBEY";
		}
	}
};
