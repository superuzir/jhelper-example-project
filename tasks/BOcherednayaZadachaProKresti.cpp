#include <iostream>

#include "../library/lib.hpp"

class BOcherednayaZadachaProKresti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll m = read_ll();

			auto vs = read_vs(n);

			vll hor(n);
			vll ver(m);
			
			forn(i, n)
			forn(j, m)
			{
				hor[i] += vs[i][j] == '*';
				ver[j] += vs[i][j] == '*';
			}

			ll mn = max_ll;
			
			forn(i, n)
			forn(j, m)
			{
				if(vs[i][j] == '*')
					mn = min(mn, m - hor[i] + n - ver[j]);
				else
					mn = min(mn, m - hor[i] + n - ver[j] - 1);
			}
			
			print mn;
		}
	}
};
