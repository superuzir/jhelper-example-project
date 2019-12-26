#include <iostream>

#include "../library/lib.hpp"

class AAbonentVremennoNedostupen
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll a = read_ll();
			ll b = read_ll();
			ll c = read_ll();
			ll r = read_ll();

			if(a > b)
				swap(a, b);

			ll a1 = c - r;
			ll b1 = c + r;

			if(b1 <= a || a1 >= b){
				print b - a;
			} else {
				ll sep = min(b1, b) - max(a1, a);

				print b - a - sep;
			}
		}
	}
};
