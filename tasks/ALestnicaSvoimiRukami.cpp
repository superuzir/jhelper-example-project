#include <iostream>

#include "../library/lib.hpp"

class ALestnicaSvoimiRukami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			vll vec = read_vll(n);

			sort(all(vec));

			print min(n - 2, vec[n - 2] - 1);
		}
	}
};
