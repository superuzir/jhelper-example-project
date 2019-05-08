#include <iostream>

#include "../library/lib.hpp"


class BLunniiNoviiGodIZakazEdi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll cnt = read_vll(n);
		vll cost = read_vll(n);

		multiset<pll> bycost;

		forn(i, n)
		{
			bycost.insert({cost[i], i});
		}

		forn(i, m)
		{
			ll req_type = read_ll() - 1;
			ll req_count = read_ll();

			ll ans = 0;
			ll idx = req_type;

			{
				ll toeat = min(cnt[idx], req_count);

				req_count -= toeat;
				cnt[idx] -= toeat;
				ans += cost[idx] * toeat;
			}

			while(req_count && bycost.size())
			{
				pll dish = *bycost.begin();
				bycost.erase(dish);

				ll idx = dish.se;

				{
					ll toeat = min(cnt[idx], req_count);

					req_count -= toeat;
					cnt[idx] -= toeat;
					ans += cost[idx] * toeat;
				}

				if(cnt[idx])
					bycost.insert({cost[idx], idx});
			}

			print req_count ? 0 : ans;
		}
	}
};
