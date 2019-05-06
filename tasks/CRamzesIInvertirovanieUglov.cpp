#include <iostream>

#include "../library/lib.hpp"
#include "../library/matrix.h"

class CRamzesIInvertirovanieUglov
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		
		vvll m1 = read_mll(n, m);
		vvll m2 = read_mll(n, m);
		
		forn(i, n)
		forn(j, m)
		{
			m1[i][j] ^= m2[i][j];
		}

		forn(i, n)
		{
			ll cnt = 0;
			forn(j, m)
			{
				if(m1[i][j])
					cnt++;
			}
			
			if(cnt % 2)
			{
				print "No";
				return;
			}
		}

		forn(j, m)
		{
			ll cnt = 0;
			forn(i, n)
			{
				if(m1[i][j])
					cnt++;
			}

			if(cnt % 2)
			{
				print "No";
				return;
			}
		}

		print "Yes";
	}
};
