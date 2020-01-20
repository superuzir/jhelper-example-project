#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

class JJustArrangeTheIcons
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll n = read_ll();
			auto v = read_vll(n);

			soa(v);

			vll c;

			itersameall(v, {
				c.pb(e - b);
			});

			soa(c);

			ll ans = max_ll;

			forn1(s, c.back() + 1){
				ll q = 0;

				forr(f, c){
					ll cnt = divceil(f, s);
					if(f < cnt * (s - 1))
					{
						q = -1;
						break;
					} else {
						q += cnt;
					}
				}

				if(q > 0)
					ans = min(ans, q);
			}

			print ans;
		}
	}
};
