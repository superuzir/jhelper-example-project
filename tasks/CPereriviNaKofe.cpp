#include <iostream>

#include "../library/lib.hpp"

class CPereriviNaKofe
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll d = read_ll();

		multiset<pll> set;
		forn(i, n)
			set.insert({read_ll(), i});

		ll day = 0;
		vll ans(n);

		while(set.size())
		{
			day++;

			for(auto it = set.begin(); it != set.end();)
			{
				ans[it->se] = day;

				ll min = it->fi;

				set.erase(it);

				it = set.lower_bound({min + d + 1, 0});
			}
		}

		print day;
		answer(ans, out);
	}
};
