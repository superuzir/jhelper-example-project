#include <iostream>

#include "../library/lib.hpp"

class EPokrivai
{


public:
	void dfs(vector<vll> & g, vll & color, ll v, ll col)
	{
		if(color[v])
			return;

		color[v] = col;

		for(auto y : g[v])
			dfs(g, color, y, col == 1 ? 2 : 1);


	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(i, q)
		{
			ll n = read_ll();
			ll m = read_ll();

			vector<vll> g(n + 1);
			vll color(n + 1, 0);

			forn(i, m)
			{
				ll a = read_ll();
				ll b = read_ll();

				g[a].pb(b);
				g[b].pb(a);
			}

//			print color;

			dfs(g, color, 1, 1);

//			print color;

			ll cnt1 = count(all(color), 1);
			ll cnt2 = count(all(color), 2);

			ll ans = cnt1 > cnt2 ? 2 : 1;

			print min(cnt1, cnt2);
			
			forn(i, n + 1)
			{
				if(color[i] == ans)
					out << i << " ";
			}
			
			out << endl;
		}


	}
};
