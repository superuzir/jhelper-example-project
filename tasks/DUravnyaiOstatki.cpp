#include <iostream>

#include "../library/lib.hpp"

class DUravnyaiOstatki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		auto v = read_vll(n);

		vector<vll> g(m);

		forn(i, n){
			ll l = v[i] % m;
			g[l].pb(i);
		}

		ll ans = 0;

		vpll s;

		forn(_, 2){
			forn(i, m){
				while(g[i].size() > n / m){
					s.pb({i, g[i].back()});
					g[i].pop_back();
				}

				while(!s.empty() && g[i].size() < n / m){
					ll d = (m + i - s.back().fi) % m;
					v[s.back().se] += d;
					ans += d;

					g[i].pb(s.back().fi);
					s.pop_back();
				}
			}
		}

		print ans;
		answer(v, out);
	}
};
