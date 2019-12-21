#include <iostream>

#include "../library/lib.hpp"

class BRavenstvoPoModulyu
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		auto a = read_vll(n);
		auto b = read_vll(n);

		soa(b);

		set<ll> sa(all(a));

		ll minb = *min_element(all(b));

		ll ans = max_ll;

		forr(sai, sa){
			ll x = sai <= minb ? minb - sai : m - (sai - minb);

			auto cand = a;

			forn(i, n){
				cand[i] = (cand[i] + x) % m;
			}

			soa(cand);

//			dbg(x);
//			print cand;
//			print b;

			if(cand == b){
				ans = min(ans, x);
			}
		}

		print ans;
	}
};
