#include <iostream>

#include "../library/lib.hpp"

class A1IgrushechniiPoezdUproshennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vector<priority_queue<ll, vll, greater<ll>>> zd(n + 1);

		forn(i, m)
		{
			ll fr = read_ll();
			ll to = read_ll();

			ll dist = to - fr;

			if(dist < 0)
				dist += n;

			zd[fr].push(dist);
		}

		vll dist;

		forn1(i, n + 1)
		{
			dist.pb(zd[i].size() ? (zd[i].size() - 1) * n + zd[i].top() : 0);
		}

//		print dist;

		forn(start, n)
		{
			ll ans = 0;

			forn(cur, n)
			{
				ll i = (start + cur) % n;
				
				if(!dist[i])
					continue;
				
				ans = max(ans, dist[i] + cur);
//				print i, ans;
			}

//			print ans;
			out << ans << " ";
		}
	}
};
