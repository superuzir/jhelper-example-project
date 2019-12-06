#include <iostream>

#include "../library/lib.hpp"

class DOcherednayaZadachaNaSrazhenieSMonstrami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t){
			ll n = read_ll();
			auto a = read_vll(n);
			ll m = read_ll();
			auto ps = read_vpll(m);

			sort(all(ps), by(se));

			vll s;
			ll maxp = 0;

			forn(i, m)
			{
				s.pb(ps[i].se);
				maxp = max(maxp, ps[i].fi);
			}

			if(maxp < *max_element(all(a)))
			{
				print -1;
				continue;
			}

			nfor1(i, m)
			{
				ps[i].fi = max(ps[i].fi, ps[i + 1].fi);
			}

			auto ok = [&](ll ss, ll p){
				auto it = lower_bound(all(s), ss);

				return it != s.end() && ps[it - s.begin()].fi >= p;
			};

			ll ans = 0;

			for(ll pos = 0; pos < n; ans++){
				ll maxmon = a[pos];

				for(ll ss = 1; ok(ss, maxmon); ss++)
				{
					if(++pos < n)
						maxmon = max(maxmon, a[pos]);
					else 
						break;
				}
			}

			print ans;
		}

	}
};
