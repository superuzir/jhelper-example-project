#include <iostream>

#include "../library/lib.hpp"

class D1PribavlenieNaDereve
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vector<vll> g(n + 1);

		forn(i, n - 1)
		{
			ll v1 = read_ll();
			ll v2 = read_ll();
			
			g[v1].pb(v2);
			g[v2].pb(v1);
		}
		
		forr(v, g)
		{
			if(v.size() == 2)
			{
				print "NO";
				return;
			}
		}

		print "YES";
	}
};
