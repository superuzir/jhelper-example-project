#include <iostream>

#include "../library/lib.hpp"


class DAromaIYeyoPoisk
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll x0 = read_ll();
		ll y0 = read_ll();
		ll ax = read_ll();
		ll ay = read_ll();
		ll bx = read_ll();
		ll by = read_ll();
		ll xs = read_ll();
		ll ys = read_ll();
		ll t = read_ll();

		vpll xy;

		xy.pb({x0, y0});

		while (1){
			ll x = xy.back().fi * ax + bx;
			ll y = xy.back().se * ay + by;

			if(x > 1e17 || y > 1e17 || x < 0 || y < 0)
				break;

			xy.pb({x, y});
		}

//		print xy.size();
//		print xy;

		ll n = xy.size();

		ll ans = 0;

		forn(i, n){
			forn(j, n){
				ll diag = abs(xy[i].fi - xy[j].fi) + abs(xy[i].se - xy[j].se);
				ll c = abs(xs - xy[i].fi) + abs(ys - xy[i].se) + diag;
				if(c < 0) continue;

				if(c <= t){
					ans = max(ans, abs(i - j) + 1);
				}
			}
		}

		print ans;
	}
};
