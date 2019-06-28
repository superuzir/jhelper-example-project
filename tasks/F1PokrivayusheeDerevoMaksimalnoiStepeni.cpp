#include <iostream>

#include "../library/lib.hpp"

class F1PokrivayusheeDerevoMaksimalnoiStepeni
{
public:
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

		ll root = 0;
		ll mx = 0;

		forn(i, n + 1)
		{
			if(g[i].size() > mx)
			{
				root = i;
				mx = g[i].size();
			}
		}

		vpll ans;

		queue<ll> q;
		q.push(root);
		vis[root] = 1;

		while(!q.empty())
		{
			ll i = q.front();
			q.pop();

			forr(v, g[i])
			{
				if(!vis[v])
				{
					vis[v] = 1;
					q.push(v);
					ans.pb({i, v});
				}
			}
		}

		forr(e, ans)
		{
			out << e.fi << " " << e.se << endl;
		}
	}
};
