#include <iostream>

#include "../library/lib.hpp"

class EKomponentiCikli
{
public:
	pll dfs(vector<vll> &g, vll &vis, ll i, std::ostream& out)
	{
		pll ans = {g[i].size(), g[i].size()};
		
		if(vis[i])
			return ans;

		vis[i] = 1;

		forr(v, g[i])
		{
			pll p = dfs(g, vis, v, out);

//			print i, v, p;

			ans.fi = min(ans.fi, p.fi);
			ans.se = max(ans.se, p.se);
		}

		return ans;
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vector<vll> g(n + 1);
		vll vis(n + 1);

		forn(i, m)
		{
			ll v1 = read_ll();
			ll v2 = read_ll();

			g[v1].pb(v2);
			g[v2].pb(v1);
		}

		ll ans = 0;

		forn1(i, n + 1)
		{
			if(vis[i])
				continue;

			pll p = dfs(g, vis, i, out);

//			print "top", i, p;

			if(p == pll(2, 2))
				ans++;
		}

		print ans;
	}
};
