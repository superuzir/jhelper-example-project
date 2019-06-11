#include <iostream>

#include "../library/lib.hpp"

typedef priority_queue<ll, vll, std::greater<ll> > Priq;

class DLunniiNoviiGodIProgulka
{
public:
	void dfs(vector<vll> &g, vll &vis, Priq &q, ll v, vll &ans)
	{
		if(vis[v])
			return;

		vis[v] = 1;

		ans.pb(v);

		forr(i, g[v])
			if(!vis[i])
				q.push(i);

		while(!q.empty())
		{
			ll i = q.top();
			q.pop();
			dfs(g, vis, q, i, ans);
		}
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

		Priq q;

		vll ans;

		dfs(g, vis, q, 1, ans);

		answer(ans, out);
	}
};
