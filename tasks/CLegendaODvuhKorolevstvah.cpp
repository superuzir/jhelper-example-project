#include <iostream>

#include "../library/lib.hpp"

class CLegendaODvuhKorolevstvah
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		forr(v, vec)
		{
			if(v < 0)
				v = -v;
		}

		sort(all(vec));

//		print vec;

		ll ans = 0;

		forn(i, n)
		{
			auto it = lower_bound(vec.begin() + i, vec.end(), 2 * vec[i] + 1);

			ll cnt = it - (vec.begin() + i) - 1;

//			print vec[i], cnt;

			ans += cnt;
		}

		print ans;
	}
};
