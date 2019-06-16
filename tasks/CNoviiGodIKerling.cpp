#include <iostream>

#include "../library/lib.hpp"

class CNoviiGodIKerling
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll r = read_ll();

		vll vec;
		vector<double> hgt;

		forn(i, n)
		{
			ll v = read_ll();

			double h = r;

			forn(j, vec.size())
			{
				ll dx = abs(v - vec[j]);
				if(dx <= 2 * r)
				{
					double hcand = hgt[j] + sqrt(4*r*r - dx*dx);
					h = max(h, hcand);
				}
			}

			hgt.pb(h);
			vec.pb(v);
		}

		answer(hgt, out);
	}
};
