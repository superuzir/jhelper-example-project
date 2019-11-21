#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class BMarchinISbori
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vector<pair<pll, bool>> v(n);

		forn(i, n) v[i].fi.fi = read_ll();
		forn(i, n) v[i].fi.se = read_ll();

		soa(v);

		itersame(all(v), [&](auto b, auto e){
			if(e - b >= 2){
				forn(i, n){
					if(b->fi.fi == (b->fi.fi | v[i].fi.fi))
						v[i].se = true;
				}
			}
		}, eq(fi.fi));

		ll ans = 0;

		forr(p, v){
			if(p.se)
				ans += p.fi.se;
		}

		print ans;
	}
};
