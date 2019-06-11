#include <iostream>

#include "../library/lib.hpp"

class CQueen
{
public:
	void dfs(vector<vll> &g, vll &vis, vll &c, ll v, vll & ans, std::ostream& out)
	{
		if(vis[v])
			return;

		vis[v] = true;

//		print v, c[v], vis, g[v];

		if(c[v] && (count_if(all(g[v]), [&](ll i){ return c[i]; }) == g[v].size() || g[v].empty()))
		{
			ans.pb(v);
		}

		forr(ch, g[v])
		{
			dfs(g, vis, c, ch, ans, out);
		}
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vector<vll> g(n + 1);
		vll c(n + 1);
		vll vis(n + 1);
		ll root = 0;

		forn1(i, n+1)
		{
			ll p = read_ll();
			c[i] = read_ll();

			if(p == -1)
			{
				root = i;
			}
			else
			{
//				g[i].pb(p);
				g[p].pb(i);
			}
		}

		vll ans;

		dfs(g, vis, c, root, ans, out);

//		print root;
//		print c;
//		print g;
		
		sort(all(ans));

		if(ans.empty())
			print -1;
		else
			answer(ans, out);
	}
};
