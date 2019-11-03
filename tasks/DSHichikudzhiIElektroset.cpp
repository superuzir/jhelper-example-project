#include <iostream>

#include "../library/lib.hpp"

class DSHichikudzhiIElektroset
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto xy = read_vpll(n);
		auto c = read_vll(n);
		auto k = read_vll(n);
		vll vis(n+1);
		vll parent(n+1, -1);

		ll cost = 0;
		vll elcity;
		vpll edge;

		forn(_, n){
			ll bestc = max_ll;
			ll besti = -1;

			forn(i, n){
				if(!vis[i] && c[i] < bestc){
					bestc = c[i];
					besti = i;
				}
			}

			cost += bestc;
			vis[besti] = 1;

			if(parent[besti] == -1)
				elcity.pb(besti + 1);
			else
				edge.pb({besti + 1, parent[besti] + 1});

			forn(i, n){
				ll cst = min(c[i], (k[i] + k[besti]) * (abs(xy[i].fi - xy[besti].fi) + abs(xy[i].se - xy[besti].se)));
				if(cst < c[i]){
					c[i] = cst;
					parent[i] = besti;
				}
			}
		}

		print cost;
		print elcity.size();
		answer(elcity, out);
		print edge.size();
		forr(e, edge) {
			print e.fi, e.se;
		}
	}
};
