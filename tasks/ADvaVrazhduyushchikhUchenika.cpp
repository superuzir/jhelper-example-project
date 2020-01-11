#include <iostream>

#include "../library/lib.hpp"

class ADvaVrazhduyushchikhUchenika
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			ll n = read_ll();
			ll x = read_ll();
			ll a = read_ll();
			ll b = read_ll();

			print min(n - 1, abs(a - b) + x);
		}
	}
};
