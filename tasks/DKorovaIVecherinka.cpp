#include <iostream>

#include "../library/lib.hpp"

class DKorovaIVecherinka
{
public:

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		Graph g(n + 1);
		vll vis(n + 1);

		forn(i, k){
			ll v1 = read_ll();
			ll v2 = read_ll();

			g[v1].pb(v2);
			g[v2].pb(v1);
		}

		ll ans = 0;

		forn1(i, n){
			if(vis[i])
				continue;

			queue<ll> q;
			q.push(i);
			vis[i] = 1;

			while(q.size()){
				ll j = q.front(); q.pop();

				forr(v, g[j]){
					if(!vis[v]){
						vis[v] = 1;
						q.push(v);
						
						ans++;
					}
				}
			}
		}
		
		print k - ans;
	}
};
