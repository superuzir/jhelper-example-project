#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class BBallsOfBuma
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto s = read_s();

		ll cnt = 0;

		itersameall(s, { cnt++; });

		if(cnt % 2 == 0){
			print 0;
			return;
		}

		auto sr = s;
		reverse(all(sr));

		vector<pair<char, ll>> v, vr;

		ll c = cnt / 2 + 1;

		itersameall(s, {
			if(c > 0){
				v.pb({*b, e - b});
				c--;
			}
		});

		c = cnt / 2 + 1;

		itersameall(sr, {
			if(c > 0){
				vr.pb({*b, e - b});
				c--;
			}
		});

//		dbg(v);
//		dbg(vr);

		forn(i, v.size() - 1){
			if(v[i].fi != vr[i].fi || v[i].se + vr[i].se < 3)
			{
				print 0;
				return;
			}
		}

		print v.back().se < 2 ? 0 : v.back().se + 1;
	}
};
