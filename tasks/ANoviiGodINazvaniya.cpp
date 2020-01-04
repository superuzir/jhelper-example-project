#include <iostream>

#include "../library/lib.hpp"

class ANoviiGodINazvaniya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		auto a = read_vs(n);
		auto b = read_vs(m);

		ll q = read_ll();

		forn(_, q){
			ll y = read_ll() - 1;

			print a[y % a.size()] + b[y % b.size()];
		}
	}
};
