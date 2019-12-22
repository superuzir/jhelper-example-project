#include <iostream>

#include "../library/lib.hpp"

class DDerevoOtrezkov
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vpll(n);

		soa(v);

		vpll konzi;

		forn(i, n){
			konzi.pb({v[i].fi, i});
			konzi.pb({v[i].se, i});
		}

		soa(konzi);

		set<pll> s;

//		dbg(konzi);

		vvll g(n);
		ll cnt_edges = 0;

		forr(b, konzi){
			if(s.count(b)){
				// This is not beginning
				s.erase(b);
			} else {
//				dbg(b);
//				dbg(s);

				forr(e, s){
					if(e.fi > v[b.se].se)
						break;

//					dbg(b, e);

					g[b.se].pb(e.se);
					g[e.se].pb(b.se);

					cnt_edges++;

					if(cnt_edges == n){
						print "NO";
						return;
					}
				}

				s.insert({v[b.se].se, b.se});
			}
		}

//		dbg(g);

		vb vis(n);

		queue<ll> q;

		q.push(0);
		vis[0] = true;

		vll pos(n);

//		dbg(g);

		ll cnt = 1;

		while(!q.empty()){
			ll from = q.front();
			q.pop();

			forr(to, g[from]){
				pos[to]++;
				if(!vis[to]){
					vis[to] = true;
					q.push(to);
					cnt++;
				}
			}
		}

		bool ok = true;

		forn(i, n)
		{
			if(pos[i] != g[i].size())
				ok = false;
		}

//		dbg(n, cnt);

		print ok && cnt == n ? "YES" : "NO";
	}
};
