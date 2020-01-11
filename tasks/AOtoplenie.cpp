#include <iostream>

#include "../library/lib.hpp"

class AOtoplenie
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		forn(_, n) {
			ll c = read_ll();
			ll sum = read_ll();

			ll k = sum / c;
			ll add = sum % c;

			print add * (k + 1) * (k + 1) + (c - add) * k * k;
		}
	}
};
