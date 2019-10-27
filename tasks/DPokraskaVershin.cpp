#include <iostream>

#include "../library/lib.hpp"

class DPokraskaVershin
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll v[3] = {
			read_vll(n),
			read_vll(n),
			read_vll(n),
		};

		vector<vll> g(n + 1);

		forn(i, n - 1) {
			ll v1 = read_ll();
			ll v2 = read_ll();

			g[v1].pb(v2);
			g[v2].pb(v1);
		}

		ll st = 0;

		forn1(i, n + 1){
			if(g[i].size() == 1)
			{
				st = i;
			}

			if(g[i].size() > 2){
				print -1;
				return;
			}
		}

		vll ans;
		ll anscost = max_ll;

//		print g;

//		dbg(st);

		auto cnt = [&](ll beg, bool up){
			vb vis(n + 1);
			vll cand(n);
			ll cost = 0;

			ll cur = st;
			cand[cur - 1] = beg + 1;
			cost += v[beg][cur - 1];
			beg = (3 + beg + (up ? 1 : -1)) % 3;

//			dbg(cur, beg, cost);

			do {
				vis[cur] = true;
				cur = g[cur].size() == 1 ? g[cur][0] : (vis[g[cur][0]] ? g[cur][1] : g[cur][0]);
				cost += v[beg][cur - 1];
				cand[cur - 1] = beg + 1;
				beg = (3 + beg + (up ? 1 : -1)) % 3;
//				dbg(cur, beg, cost);
			} while(g[cur].size() == 2);

			if(cost < anscost)
			{
				anscost = cost;
				ans = cand;
			}

//			dbg(cost);
		};

		forn(beg, 3)
		forn(up, 2)
			cnt(beg, up);

		print anscost;
		answer(ans, out);
	}
};
