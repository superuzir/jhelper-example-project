#include <iostream>

#include "../library/lib.hpp"


class ASummaVDereve
{
public:
	void dfs(Graph &g, vector<bool> &vis, vll & s, vll & a, bool &ok, int i, ll sp)
	{
		if(vis[i])
			return;

		vis[i] = true;

		if(s[i] == -1)
		{
			ll mn = max_ll;
			forr(v, g[i])
			{
				mn = min(mn, s[v]);
			}
			s[i] = g[i].size() ? mn : sp;
		}

		if(s[i] < sp)
			ok = false;

		a[i] = s[i] - sp;

		forr(v, g[i])
		{
			dfs(g, vis, s, a, ok, v, s[i]);
		}
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		Graph g(n + 1);
		vector<bool> vis(n + 1);
		vll s(n + 1);
		vll a(n + 1);


		forn(i, n - 1)
		{
			ll v1 = read_ll();
			ll v2 = i + 2;

			g[v1].pb(v2);
//			g[v2].pb(v1);
		}

		forn(i, n)
		{
			s[i + 1] = read_ll();
		}

		bool ok = true;

		dfs(g, vis, s, a, ok, 1, 0);

//		print a;

		print ok ? sua(a) : -1;
	}
};
