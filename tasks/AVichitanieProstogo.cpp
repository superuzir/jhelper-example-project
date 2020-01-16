#include <iostream>

#include "../library/lib.hpp"

class AVichitanieProstogo
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q) {
			ll x = read_ll();
			ll y = read_ll();

			print x - y == 1 ? "NO" : "YES";
		}
	}
};
