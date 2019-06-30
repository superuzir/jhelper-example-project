#include <iostream>

#include "../library/lib.hpp"
#include "../library/dsu.h"


class FAsyaIKotyata
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		map<ll, vll> map;

		Dsu d(n);
		forn(i, n)
		{
			d.make(i);
			map[i] = vll(1, i);
		}

//		print map;
//		d.out(out);

		forn(i, n - 1)
		{
			ll c1 = read_ll() - 1;
			ll c2 = read_ll() - 1;

			ll pc1 = d.find(c1);
			ll pc2 = d.find(c2);
			ll pc3 = d.unite(c1, c2);

			ll pce = pc3 == pc1 ? pc2 : pc1;

			vll & beg = map[pc3];
			vll & en = map[pce];
			beg.insert(beg.end(), all(en));
			map.erase(pce);

//			print "map", map;
//			d.out(out);
		}

		vll & ans = map.begin()->se;
		forr(a, ans)
			a++;
		answer(ans, out);
	}
};
