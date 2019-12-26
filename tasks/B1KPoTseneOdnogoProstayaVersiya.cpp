#include <iostream>

#include "../library/lib.hpp"

class B1KPoTseneOdnogoProstayaVersiya
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

			ll ans1 = 0;
			ll ans2 = 0;

			{
				ll p1 = p;

				for (ll i = 0; i < n; i += 2)
				{
					if (p1 >= v[i])
					{
						p1 -= v[i];
						ans1 += i == 0 ? 1 : 2;
					}
					else
					{
						if (i != 0 && p1 >= v[i - 1])
						{
							ans1++;
						}
						break;
					}
				}
			}

			{
				ll p1 = p;

				for (ll i = 1; i < n; i += 2)
				{
					if (p1 >= v[i])
					{
						p1 -= v[i];
						ans2 += i == 0 ? 1 : 2;
					}
					else
					{
						if (i != 0 && p1 >= v[i - 1])
						{
							ans2++;
						}
						break;
					}
				}
			}

			print max(ans1, ans2);
		}
	}
};
