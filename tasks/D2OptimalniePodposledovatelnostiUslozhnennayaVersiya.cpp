#include <iostream>

#include "../library/lib.hpp"
#include "../library/pbds.h"


class D2OptimalniePodposledovatelnostiUslozhnennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vlli(n);
		ll m = read_ll();
		auto req = read_vplli(m);

		forr(vv, v){ vv.se *= -1; }
		sort(rall(v));
		forr(vv, v){ vv.se *= -1; }

		soa(req);

		ordered_set<pll> set;

		forr(r, req){
			while(set.size() < r.fi.fi){
				auto & i = v[set.size()];
				set.insert({i.se, i.fi});
			}

			r.fi.fi = set.find_by_order(r.fi.se - 1)->se;
		}

		sort(all(req), by(se));

		forr(r, req){
			print r.fi.fi;
		}
	}
};
