#include <iostream>

#include "../library/lib.hpp"

class C1HoroshieChislaProstayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vll v;

		for(ll st = 1; st < 30000; st *= 3) {
			ll n = v.size();

			v.pb(st);
			forn(i, n) {
				v.pb(v[i] + st);
			}
		}

		ll q = read_ll();
		forn(_,  q){
			ll n = read_ll();
			print *lower_bound(all(v), n);
		}
	}
};
