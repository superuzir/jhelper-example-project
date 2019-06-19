#include <iostream>

#include "../library/lib.hpp"

class FGrafBezDlinnihOrientirovannihPutei
{
public:
	void dfs(vector<vll> &g, vll &col, ll v, ll c)
	{
		if(col[v])
		{
			if(col[v] != c)
				col[v] = 3;
			return;
		}

		col[v] = c;

		forr(i, g[v])
		{
			dfs(g, col, i, c == 1 ? 2 : 1);
		}
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vector<vll> g(n + 1);
		vll col(n + 1);

		vpll edges;

		forn(i, m)
		{
			ll v1 = read_ll();
			ll v2 = read_ll();

			g[v1].pb(v2);
			g[v2].pb(v1);

			edges.pb({v1, v2});
		}

		dfs(g, col, 1, 1);
		
		string ans;
		
		forr(e, edges)
		{
			if(col[e.fi] == 3 || col[e.se] == 3)
			{
				print "NO";
				return;
			}
			
			ans += col[e.fi] == 1 ? '1' : '0';
		}
		
		print "YES";
		print ans;
	}
};
