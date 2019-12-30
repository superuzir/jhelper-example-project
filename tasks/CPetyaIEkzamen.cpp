#include <iostream>

#include "../library/lib.hpp"

class CPetyaIEkzamen
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll T = read_ll();
			ll a = read_ll();
			ll b = read_ll();

			vll len = read_vll(n);
			vll t = read_vll(n);


			vpll e(n);

			forn(i, n){
				e[i] = {t[i], len[i]};
			};

			e.push_back({T + 1, 0});

			soa(e);

			ll ca = count(all(len), 0);
			ll cb = count(all(len), 1);

			ll oba = 0;
			ll obb = 0;

			ll ans = 0;

			forn(i, e.size())
			{
				ll sumlen = oba * a + obb * b;

				ll freelen = e[i].fi - 1 - sumlen;
				if(freelen >= 0){
					ll adda = min(ca - oba, freelen / a);
					freelen -= adda * a;
					ll addb = min(cb - obb, freelen / b);

					ans = max(ans, oba + obb + adda + addb);
				}

				forlr(j, i, e.size()){
					if(e[i].fi == e[j].fi){
						if(e[j].se)
							obb++;
						else
							oba++;
					} else {
						i = j - 1;
						break;
					}
				}
			}

			print ans;
		}
	}
};
