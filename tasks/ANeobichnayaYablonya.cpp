#include <iostream>

#include "../library/lib.hpp"

class ANeobichnayaYablonya
{
public:
	void dfs(vector<vll> &g, vll &vis, vll &lrs, int v, int lr)
	{
		if(vis[v])
			return;
		
		vis[v] = 1;
		
		lrs[lr]++;
		
		forr(i, g[v])
			dfs(g, vis, lrs, i, lr + 1);
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		
		vector<vll> g(n + 1);
		vll vis(n + 1);
		vll lrs(n + 1);
		
		forn(i, n - 1)
		{
			ll v = read_ll();
			
			g[v].pb(i + 2);
			g[i + 2].pb(v);
		}
		
		dfs(g, vis, lrs, 1, 0);
		
		ll ans = 0;
		
		forr(l, lrs)
			ans += l%2;
		
		print ans;
	}
};
