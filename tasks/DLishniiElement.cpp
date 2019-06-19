#include <iostream>

#include "../library/lib.hpp"

class DLishniiElement
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vpll v;

		forn(i, n)
		{
			v.pb({read_ll(), i});
		}

		sort(all(v));
		
		if(n < 4)
		{
			print v[0].se + 1;
			return;
		}

		{
			ll a1 = v[0].fi;
			ll c = v[1].fi - v[0].fi;
			ll cnt = 0;
			ll ans = v[0].se + 1;

			{
				forn(i, n)
				{
					if (a1 + c * (i - cnt) != v[i].fi)
					{
						cnt++;
						ans = v[i].se + 1;
					}
				}

				if (cnt <= 1)
				{
					print ans;
					return;
				}
			}
		}

		{
			ll a1 = v[0].fi;
			ll c = v[2].fi - v[0].fi;
			ll cnt = 0;
			ll ans = v[0].se + 1;

			{
				forn(i, n)
				{
					if (a1 + c * (i - cnt) != v[i].fi)
					{
						cnt++;
						ans = v[i].se + 1;
					}
				}

				if (cnt <= 1)
				{
					print ans;
					return;
				}
			}
		}

		{
			ll a1 = v[1].fi;
			ll c = v[2].fi - v[1].fi;
			ll cnt = 0;
			ll ans = v[0].se + 1;

			{
				forn(i, n)
				{
					if (a1 + c * (i - cnt) != v[i].fi)
					{
						cnt++;
						ans = v[i].se + 1;
					}
				}

				if (cnt <= 1)
				{
					print ans;
					return;
				}
			}
		}

		print -1;
	}
};
