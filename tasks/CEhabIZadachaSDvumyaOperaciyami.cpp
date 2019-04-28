#include <iostream>

#include "../library/lib.hpp"

class CEhabIZadachaSDvumyaOperaciyami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		print n + 1;

		{
			ll val = 2 * n + 1;

			forn(i, n)
			{
				vec[i] += val;
			}

			print 1, n, val;
		}

		forn(i, n)
		{
			ll val = vec[i] - (i + 1);

			forn(j, i + 1)
			{
				vec[j] %= val;
			}

			print 2, i + 1, val;
		}
	}
};
