#include <iostream>

#include "../library/lib.hpp"

class DIzmenenieZarplat
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q){
			ll n = read_ll();
			ll s = read_ll();
			auto vec = read_vpll(n);

			ll l = 0;
			ll r = s + 1;
			ll ans = 0;

			while(l < r){
				ll m = (l + r) / 2;

				vpll cand;

				ll lo = 0;
				ll hi = 0;
				ll zp = 0;

				forr(v, vec){
					if(v.se < m){
						lo++;
						zp += v.fi;
					} else if(v.fi > m){
						hi++;
						zp += v.fi;
					} else {
						cand.pb(v);
					}
				}

				soa(cand);

				if(hi > n / 2){
					l = m + 1;
				} else if(lo > n / 2){
					r = m;
				} else {
					forr(c, cand){
						if(lo < n / 2){
							zp += c.fi;
						} else {
							zp += m;
						}
						lo++;
					}

					if(zp > s){
						r = m;
					} else {
						l = m + 1;
						ans = max(ans, m);
					}
				}
			}

			print ans;
		}
	}
};
