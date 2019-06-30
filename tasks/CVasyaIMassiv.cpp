#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class CVasyaIMassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vpll srt;
		vpll srtmrg;
		vpll uns;

		forn(i, m)
		{
			ll t = read_ll();
			ll l = read_ll();
			ll r = read_ll();

			if(t)
				srt.pb({l, r});
			else
				uns.pb({l, r});
		}

		sort(all(srt));

		srtmrg.pb(srt[0]);

		forn1(i, srt.size())
		{
			if(srtmrg.back().se >= srt[i].fi)
				srtmrg.back().se = max(srtmrg.back().se, srt[i].se);
			else
				srtmrg.pb(srt[i]);
		}

		forr(u, uns)
		forr(s, srtmrg)
		{
			if(u.fi >= s.fi && u.se <= s.se)
			{
				print "NO";
				return;
			}
		}

		vll ans(n);

		forr(s, srtmrg)
		{
			forlr(i, s.fi - 1, s.se)
			{
				if(i == s.fi - 1)
					ans[i] = 1;
				else
					ans[i] = 7777;
			}
		}

		itersameall(ans, {
			if(*b == 0)
			{
				ll v = 6000;
				for(; b != e; ++b)
					*b = v--;
			}
		});

//		print ans;
//		print srt;
//		print srtmrg;
//		print uns;

		print "YES";
		answer(ans, out);
	}
};
