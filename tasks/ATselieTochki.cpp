#include <iostream>

#include "../library/lib.hpp"

class ATselieTochki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t) {

			ll n = read_ll();
			auto p = read_vll(n);

			ll m = read_ll();
			auto q = read_vll(m);

			ll p0 = count_if(all(p), [](ll x){ return x % 2 == 0; });
			ll p1 = count_if(all(p), [](ll x){ return x % 2 == 1; });
			ll q0 = count_if(all(q), [](ll x){ return x % 2 == 0; });
			ll q1 = count_if(all(q), [](ll x){ return x % 2 == 1; });

			print p0 * q0 + p1 * q1;
		}
	}
};
