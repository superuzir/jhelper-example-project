#include <iostream>

#include "../library/lib.hpp"

class DServalIPodveshennoeDerevo
{
public:
	ll leafs = 0;

	ll dfs(Graph &g, vb &vis, vll &mm, ll i)
	{
		vis[i] = true;

		if(mm[i] == 0){
			// min
			ll ans = 0;
			bool leaf = true;

			forr(v, g[i]){
				if(!vis[v])
				{
					leaf = false;
					ans += dfs(g, vis, mm, v);
				}
			}

			if(leaf)
				leafs++;

			return leaf ? 1 : ans;
		} else {
			// max

			ll ans = max_ll;
			bool leaf = true;

			forr(v, g[i]){
				if(!vis[v])
				{
					leaf = false;
					ans = min(ans, dfs(g, vis, mm, v));
				}
			}

			if(leaf)
				leafs++;

			return leaf ? 1 : ans;
		}
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vll mm(1);

		forn(i, n)
			mm.pb(read_ll());

		Graph g(n + 1);
		vb vis(n + 1);

		forlr(v1, 2, n + 1){
			ll v2 = read_ll();

			g[v1].pb(v2);
			g[v2].pb(v1);
		}

		ll ans = dfs(g, vis, mm, 1ll);

//		dbg(ans, leafs);
		
		print leafs - ans + 1;
	}
};
