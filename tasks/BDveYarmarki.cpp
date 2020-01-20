#include <iostream>

#include "../library/lib.hpp"

class BDveYarmarki
{
	ll dfs(const Graph & g, vb & vis, ll i, ll nogo){
		if(vis[i])
			return 0;

		vis[i] = true;

		ll cnt = 1;

		if(i != nogo) {
			forr(u, g[i]) {
				cnt += dfs(g, vis, u, nogo);
			}
		}

		return cnt;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll n = read_ll();
			ll m = read_ll();
			ll a = read_ll();
			ll b = read_ll();

			Graph g(n + 1);

			forn(i, m){
				ll u = read_ll();
				ll v = read_ll();

				g[u].pb(v);
				g[v].pb(u);
			}

			vb vis(n + 1);

			ll ca = n - dfs(g, vis, a, b);

			vis = vb(n + 1);

			ll cb = n - dfs(g, vis, b, a);

			print ca * cb;
		}
	}
};
