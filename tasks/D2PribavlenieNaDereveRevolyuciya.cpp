#include <iostream>

#include "../library/lib.hpp"

class D2PribavlenieNaDereveRevolyuciya
{
public:
	void dfs(vector<map<ll, pll>> &g, vll &vis, ll i, ll leaf, std::ostream& out)
	{
		if(vis[i])
			return;

		vis[i] = 1;

		forr(v, g[i])
		{
			if(!vis[v.fi])
				g[v.fi][i].se = leaf;
//			if(leaf == 3)
//			{
//				print i, v.fi, leaf;
//			}
			dfs(g, vis, v.fi, leaf, out);

		}
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vector<map<ll, pll>> g(n + 1);  // K-sosed V-<weight, list>

		forn(i, n - 1)
		{
			ll v1 = read_ll();
			ll v2 = read_ll();
			ll w = read_ll();

			g[v1][v2] = {w, -1};
			g[v2][v1] = {w, -1};
		}

		forr(v, g)
		{
			if(v.size() == 2 && v.begin()->se.fi != next(v.begin())->se.fi)
			{
				print "NO";
				return;
			}
		}

		print "YES";

		forn1(i, g.size())
		{
			if(g[i].size() == 1)
			{
				vll vis(n + 1);
				dfs(g, vis, i, i, out);
			}
		}

		print g;


		forn1(i, g.size())
		{
			if (g[i].size() > 2)
			{
				for(auto it = g[i].begin(); it != g[i].end(); ++it)
				{
					auto it2 = it;
					auto it3 = it;

					++it2;
					++it3;

					if(it2 == g[i].end())
						break;

					++it2;

					if(it3 == g[i].end())
						break;

					vll vis(n + 1);
					update(g, vis, i);
				}
			}
		}
	}
};
