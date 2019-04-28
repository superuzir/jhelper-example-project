#include <iostream>

#include "../library/lib.hpp"

class BDimaIPlohoiXOR
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vector<vll> vec(n);

		forn(i, n)
			vec[i] = read_vll(m);

		ll ftry = 0;

		forn(i, n)
			ftry ^= vec[i][0];

		if(ftry > 0)
		{
			print "TAK";
			answer(vll(n, 1), out);
			return;
		}
		else
		{
			forn(i, n)
			{
				forn1(j, m)
				{
					if(vec[i][j] != vec[i][0])
					{
						print "TAK";
						vll ans(n, 1);
						ans[i] = j + 1;
						answer(ans, out);
						return;
					}
				}
			}
		}

		print "NIE";
	}
};
