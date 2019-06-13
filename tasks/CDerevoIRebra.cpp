#include <iostream>

#include "../library/lib.hpp"

class CDerevoIRebra
{
	ll pow(ll a, ll b, ll m)
	{
		ll ans=1;
		while(b)
		{
			if(b&1)
				ans=(ans*a)%m;
			b/=2;
			a=(a*a)%m;
		}
		return ans;
	}

	ll dfs(vector<vll> & g, vll &vis, ll i)
	{
		if(vis[i])
			return 0;

		vis[i] = 1;

		ll ans = 1;

		forr(v, g[i])
			ans += dfs(g, vis, v);

		return ans;
	}

public:

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		vector<vll> g(n + 1);
		vll vis(n + 1);

		forn1(i, n + 1)
		{
			g[i].pb(i);
		}

		forn(i, n - 1)
		{
			ll v1 = read_ll();
			ll v2 = read_ll();
			ll col = read_ll();

			if(!col)
			{
				g[v1].pb(v2);
				g[v2].pb(v1);
			}
		}

		ll bad = 0;

		forn1(i, n + 1)
		{
			ll b = dfs(g, vis, i);

			bad += pow(b, k, MOD);
			bad %= MOD;
		}

		print (pow(n, k, MOD) - bad + MOD) % MOD;
	}
};
