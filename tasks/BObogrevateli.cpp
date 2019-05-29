#include <iostream>

#include "../library/lib.hpp"

class BObogrevateli
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll r = read_ll() - 1;
		vll vec = read_vll(n);

		ll ans = 0;

		forn(i, n)
		{
			ll place = -1;
			for(ll j = min(n - 1, i + r); j >= max(0ll, i - r); j--)
			{
				if(vec[j] == 1)
				{
					place = j;
					break;
				}
			}

			if(place == -1)
			{
				print -1;
				return;
			}
			else
			{
				ans++;
//				print i, place;
				i = place + r;
			}
		}

		print ans;
	}
};
