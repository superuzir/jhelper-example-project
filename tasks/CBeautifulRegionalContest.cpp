#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class CBeautifulRegionalContest
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();
		forn(_, t){
			ll n = read_ll();
			auto v = read_vll(n);

			if(n < 3)
			{
				print 0, 0, 0;
				continue;
			}


			ll m = n / 2;

			nfor(i, n / 2)
			{
				if(i == 0)
					break;

				if(v[i] == v[i + 1])
					m--;
				else
					break;
			}

//			print v;
//			print n, m;

			ll g = 0;
			ll s = 0;
			ll br = 0;

			v.resize(m);

			itersameall(v, {
				if(g == 0)
				{
					g = e - b;
				}
				else if(s <= g)
				{
					s += e - b;
				}
				else {
					br += e - b;
				}
			});

			if(g && s && br && g < s && g < br)
				print g, s, br;
			else
				print 0, 0, 0;
		}
	}
};
