#include <iostream>

#include "../library/lib.hpp"

class CZadominirovanniiPodmassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q) {
			ll n = read_ll();
			auto v = read_vlli(n);

			soa(v);

			ll ans = max_ll;

			forn1(i, n){
				if(v[i - 1].fi == v[i].fi){
					ans = min(ans, v[i].se - v[i - 1].se + 1);
				}
			}

			print ans == max_ll ? -1 : ans;
		}
	}
};
