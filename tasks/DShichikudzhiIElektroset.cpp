#include <iostream>

#include "../library/lib.hpp"

class DShichikudzhiIElektroset
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto xy = read_vpll(n);
		auto c = read_vll(n);
		auto k = read_vll(n);

		ll cost = 0;
		vb vis(n);
		vll par(n, -1);
		vll el;
		vpll edge;

		forn(_, n){
			ll mincost = max_ll;
			ll mini = 0;

			forn(i, n){
				if(!vis[i] && c[i] < mincost){
					mincost = c[i];
					mini = i;
				}
			}

			cost += mincost;
			vis[mini] = true;

			if(par[mini] == -1){
				el.pb(mini + 1);
			} else {
				edge.pb({mini + 1, par[mini] + 1});
			}

			forn(i, n){
				if(i == mini)
					continue;

				ll costdor = (k[mini] + k[i]) * (abs(xy[mini].fi - xy[i].fi) + abs(xy[mini].se - xy[i].se));

				if(costdor < c[i]){
					c[i] = costdor;
					par[i] = mini;
				}
			}
		}

		print cost;

		print el.size();
		answer(el, out);

		print edge.size();
		forr(e, edge){
			print e.fi, e.se;
		}
	}
};
