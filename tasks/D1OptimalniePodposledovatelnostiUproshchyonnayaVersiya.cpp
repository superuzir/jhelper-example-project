#include <iostream>

#include "../library/lib.hpp"
#include "../library/pbds.h"


class D1OptimalniePodposledovatelnostiUproshchyonnayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vlli(n);

		ll qn = read_ll();
		auto q = read_vplli(qn);

		auto v1 = v;

		forn(i, n) v[i].fi *= -1;

		soa(v);
		soa(q);

		ordered_set<ll> s;

		forr(qi, q){
			while(s.size() < qi.fi.fi){
				s.insert(v[s.size()].se);
			}

			qi.fi.se = v1[*s.find_by_order(qi.fi.se - 1)].fi;
		}

		sort(all(q), by(se));

		forr(qi, q){
			print qi.fi.se;
		}
	}
};
