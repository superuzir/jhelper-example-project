#include <iostream>

#include "../library/lib.hpp"

class BOcherednayaMemnayaZadacha
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll a = read_ll();
			ll b = read_ll();

			ll ans = 0;

			ll c = 10;

			while(c - 1 <= b){
			    ans += a;

			    c *= 10;
			}

			print ans;
		}
	}
};
