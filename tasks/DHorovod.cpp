#include <iostream>

#include "../library/lib.hpp"

class DHorovod
{
public:
	void dfs(vector<vll> & g, vector<bool> & vis, vll & ans, int i)
	{
		if(vis[i])
			return;

		vis[i] = true;

		forr(v, g[i])
		{
			dfs(g, vis, ans, v);
		}

		ans.pb(i);
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto vec = read_vpll(n);

		vector<vll> g(n + 1);
		vector<bool> vis(n + 1);

		forr(v, vec)
		{
			g[v.fi].pb(v.se);
			g[v.se].pb(v.fi);
		}

		vll ans;

		dfs(g, vis, ans, 1);

		{
			auto it1 = find(all(ans), 1);
			auto it2 = it1 + 1;
			if(it2 == ans.end()) it2 = ans.begin();
			auto it3 = it2 + 1;
			if(it3 == ans.end()) it3 = ans.begin();
			
			if(vec[0].fi != *it2 && vec[0].fi != *it3)
				reverse(all(ans));
		}
		
		answer(ans, out);
	}
};
