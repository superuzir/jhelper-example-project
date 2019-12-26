#include <iostream>

#include "../library/lib.hpp"

class B2KPoTseneOdnogoUslozhnyonnayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll p = read_ll();
			ll k = read_ll();

			auto v = read_vll(n);

			soa(v);

			ll ans = 0;
			ll sumf = 0;

			forlr(st, -1, k){
				sumf += st < 0 ? 0 : v[st];

				ll p1 = p - sumf;
				ll ans1 = p1 >= 0 ? st + 1 : 0;

//				dbg(st, sumf, p1, ans1);

				for (ll i = st + k; i < n; i += k)
				{
					if(p1 >= v[i])
					{
						ans1 += k;
						p1 -= v[i];
					}
				}

				ans = max(ans, ans1);
			}

			print ans;
		}

	}
};
