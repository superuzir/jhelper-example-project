#include <iostream>

#include "../library/lib.hpp"

class CPoleznayaDekompoziciya
{
	void dfs(vector<vll> &g, vll &vis, ll i, std::ostream& out, ll & end)
	{
		if(vis[i])
			return;

		vis[i] = 1;

		forr(v, g[i])
			dfs(g, vis, v, out, end);

		if(g[i].size() == 1)
			end = i;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vector<vll> g(n + 1);
		vll vis(n + 1);

		forn(i, n - 1)
		{
			ll v1 = read_ll();
			ll v2 = read_ll();

			g[v1].pb(v2);
			g[v2].pb(v1);
		}

		ll root = 0;
		ll root2 = 0;

		forn1(i, n + 1)
		{
			if(g[i].size() > 2)
			{
				if(root)
				{
					print "No";
					return;
				}

				root = i;
			}

			if(g[i].size() == 1)
				root2 = i;
		}

		if(!root)
			root = root2;

		vis[root] = 1;

		print "Yes";
		print g[root].size();

		forr(v, g[root])
		{
			ll end;
			dfs(g, vis, v, out, end);
			print root, end;
		}
	}
};
