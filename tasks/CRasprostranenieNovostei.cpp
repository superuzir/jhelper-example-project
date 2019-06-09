#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class CRasprostranenieNovostei
{
public:
	void dfs(vector<vll> &g, vll &color, ll u, ll c)
	{
		if(color[u] != -1)
			return;

		color[u] = c;

		forr(el, g[u])
			dfs(g, color, el, c);
	}

	struct User
	{
		ll idx;
		ll color;
		ll ans;
	};

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vector<vll> g(n + m);
		vll color(n + m, -1);

		forn(i, m)
		{
			ll k = read_ll();

			forn(j, k)
			{
				ll u = read_ll() - 1;

				g[u].pb(n + i);
				g[n + i].pb(u);
			}
		}

		vll ans(n);

		forn(i, n)
		{
			dfs(g, color, i, i);
		}

		vector<User> us(n);

		forn(i, n)
		{
			us[i] = {i, color[i], 0};
		}

		sort(all(us), by(color));

		itersame(all(us), [&](auto b, auto e){
			ll ans = e - b;
			for(; b != e; ++b)
			{
				b->ans = ans;
			}
		}, eq(color));

		sort(all(us), by(idx));
		
		forn(i, n)
		{
			out << us[i].ans << " ";
		}
		
		out << endl;

//		print color;
	}
};
