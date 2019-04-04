#include <iostream>

#include "../library/lib.hpp"

class BPingvinPoloIMatrica
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll d = read_ll();
		vll vec = read_vll(m * n);

		ll sum = 0;

		forn(i, n * m)
		{
			if(vec[i] % d)
			{
				print -1;
				return;
			}
			else
			{
				vec[i] /= d;

				sum += vec[i];
			}
		}

		
	}
};
