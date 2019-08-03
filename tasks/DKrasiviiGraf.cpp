#include <iostream>

#include "../library/lib.hpp"

class DKrasiviiGraf
{
public:
	void dfs(Graph &g, set<ll> & gvis, int i, vll & col, vll & col2, ll colcur, bool& ok)
	{
		if(col[i] && col[i] != colcur)
			ok = false;

		if(col[i])
			return;

		gvis.insert(i);

		col[i] = colcur;
		col2[colcur]++;

		forr(v, g[i])
		{
			dfs(g, gvis, v, col, col2, colcur == 1 ? 2 : 1, ok);
		}
	}

	void solve(std::istream& in, std::ostream& out)
	{
		vll p(1000000);

		{
			ll pp = 1;
			forn(i, p.size())
			{
				p[i] = pp;
				pp *= 2;
				pp %= 998244353;
			}
		}

		ll q = read_ll();

		forn(__, q)
		{
			ll n = read_ll();
			ll m = read_ll();

			Graph g(n + 1);

			forn(i, m)
			{
				ll v1 = read_ll();
				ll v2 = read_ll();

				g[v1].pb(v2);
				g[v2].pb(v1);
			}

			bool ok = true;

			set<ll> gvis;
			vll col(n + 1);

			vll vans;

			forn1(root, n + 1)
			{
				if(gvis.count(root))
					continue;

				if(g[root].empty())
				{
					vans.pb(3);
					continue;
				}

				ll ans = 0;

				vll col2(3);
				dfs(g, gvis, root, col, col2, 1, ok);

				ans += p[col2[1]] + p[col2[2]];
				ans %= 998244353;

				vans.pb(ans);
			}

			ll ans = vans[0];

			forn1(i, vans.size())
			{
				ans *= vans[i];
				ans %= 998244353;
			}

//			print vans;

			print ok ? ans : 0;
		}
	}
};
