#include <iostream>

#include "../library/lib.hpp"

class C1HaidiITestTyuringaLegkaya
{
	bool isSq(std::ostream& out, const vpll & vec)
	{
		pll v1 = {max_ll, max_ll};
		pll v2 = {min_ll, min_ll};
		
		forr(p, vec)
		{
			v1.fi = min(v1.fi, p.fi);
			v1.se = min(v1.se, p.se);
			v2.fi = max(v2.fi, p.fi);
			v2.se = max(v2.se, p.se);
		}

		if(v2.fi - v1.fi != v2.se - v1.se)
			return false;
		
//		dbg(v1, v2);

		forr(p, vec)
		{
//			dbg(p);
			if(p.fi != v1.fi && p.fi != v2.fi && p.se != v1.se && p.se != v2.se) return false;
//			dbg(p);
			if(p.fi < v1.fi || p.fi > v2.fi || p.se < v1.se || p.se > v2.se) return false;
		}

		return true;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto vec = read_vpll(4*n+1);
		soa(vec);

		forn(i, vec.size())
		{
			pll a = vec[i];

			vec.erase(vec.begin() + i);

			if(isSq(out, vec))
			{
				print a.fi, a.se;
				return;
			}

			vec.pb(a);
			soa(vec);
		}
	}
};
