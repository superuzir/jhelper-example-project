#include <iostream>

#include "../library/lib.hpp"

class DIzmenenieZarplat
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			ll s = read_ll();
			auto vec = read_vpll(n);

			ll l = 1;
			ll r = 1e9 + 2.5;
			ll ans = 0;

			while(l < r - 1) {
				ll m = (r + l) / 2;

				ll clo = 0;
				ll chi = 0;
				vpll cand;

				ll total = 0;

				forr(a, vec){
					if(a.fi > m) {
						chi++;
						total += a.fi;
					}
					else if(a.se < m) {
						clo++;
						total += a.fi;
					}
					else cand.pb(a);
				}

				soa(cand);

//				dbg(salmin, salmax, clo, chi, cand);


				if(clo > n / 2) {
					r = m;
				} else if(chi > n / 2) {
					l = m;
				} else {
					ll mcand = n / 2 - clo;

					forn(i, mcand) {
						total += cand[i].fi;
					}

					forlr(i, mcand, cand.size()){
						total += m;
					}

					if(total <= s){
						ans = max(m, ans);
						l = m;
					} else {
						r = m;
					}
				}
			}

			print ans;
		}
	}
};
