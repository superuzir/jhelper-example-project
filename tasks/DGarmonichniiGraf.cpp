#include <iostream>

#include "../library/lib.hpp"

class DGarmonichniiGraf
{
	void dfs(const Graph & g, vb & vis, ll & cnt, ll & mx, ll i){
		if(vis[i])
			return;

		vis[i] = true;

		cnt++;
		mx = max(mx, i);

		forr(u, g[i])
			dfs(g, vis, cnt, mx, u);
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		Graph g(n + 1);

		forn(i, m){
			ll u = read_ll();
			ll v = read_ll();

			g[u].pb(v);
			g[v].pb(u);
		}

		vb vis(n + 1);

		ll ans = 0;

		forn1(i, n + 1){
			if(vis[i])
				continue;

			ll cnt = 0;
			ll mx = i;

			ll st = i;

			ll q = 0;

			while(cnt < mx - i + 1){
				forlr(j, st, n){
					if(!vis[j]) {
						st = j;
						break;
					}
				}

				dfs(g, vis, cnt, mx, st);

				q++;
			}

			ans += q - 1;
		}

		print ans;
	}
};
