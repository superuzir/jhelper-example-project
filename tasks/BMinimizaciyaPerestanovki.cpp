#include <iostream>

#include "../library/lib.hpp"

class BMinimizaciyaPerestanovki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			auto v = read_vll(n);

			auto b = v.begin();

			while(b != v.end()){
				auto mn = min_element(b, v.end());

				ll val = *mn;

				copy(b, mn, b + 1);

				*b = val;

				b = mn + (mn == b);
			}

			answer(v, out);
		}
	}
};
