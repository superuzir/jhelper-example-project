#include <iostream>

#include "../library/lib.hpp"
#include "../library/matrix.h"


class CNastyaTransponiruetMatricu
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vvll m1 = read_mll(n, m);
		vvll m2 = read_mll(n, m);

		vvll d1(n + m - 1);
		vvll d2(n + m - 1);

		forn(i, n)
		forn(j, m)
		{
			d1[i + j].pb(m1[i][j]);
			d2[i + j].pb(m2[i][j]);
		}

		forr(d, d1) sort(all(d));
		forr(d, d2) sort(all(d));

		print equal(all(d1), d2.begin()) ? "YES" : "NO";
	}
};
