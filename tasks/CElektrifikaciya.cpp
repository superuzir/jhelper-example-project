#include <iostream>

#include "../library/lib.hpp"

class CElektrifikaciya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(i, t)
		{
			ll n = read_ll();
			ll k = read_ll();

			vll vec = read_vll(n);

			ll md = max_ll;
			ll ans;

			for(ll i = 0; i + k < n; i++)
			{
				ll dist = vec[i + k] - vec[i];
				
				if(dist < md)
				{
					md = dist;
					ans = (vec[i + k] + vec[i]) / 2;
				}
				
//				print "df", vec[i + k], vec[i];
			}

			print ans;
		}
	}
};
