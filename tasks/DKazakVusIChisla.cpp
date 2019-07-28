#include <iostream>

#include "../library/lib.hpp"

class DKazakVusIChisla
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		auto vec = vin<double>(n, in);
		vll vecf(n);

		forn(i, n)
		{
			vecf[i] = floor(vec[i]);
		}

		ll sum = sua(vecf);

		forn(i, n)
		{
			if(abs(vec[i] - vecf[i]) < 1e-7)
			{
				print vecf[i];
				continue;
			}

			if(sum)
			{
				print vecf[i] + 1;
				sum++;
			}
			else
			{
				print vecf[i];
			}
		}
	}
};
