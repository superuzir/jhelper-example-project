#include <iostream>

#include "../library/lib.hpp"

class BDvoinayaMatrica
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vector<vll> m1(n);
		vector<vll> m2(n);

		forn(i, n) m1[i] = read_vll(m);
		forn(i, n) m2[i] = read_vll(m);

		forn(i, n)
		forn(j, m)
		{
			if(m1[i][j] > m2[i][j])
				swap(m1[i][j], m2[i][j]);
		}


		forn1(i, n)
		forn1(j, m)
		{
			ll e11 = m1[i - 1][j - 1];
			ll e12 = m1[i - 1][j];
			ll e21 = m1[i][j - 1];
			ll e22 = m1[i][j];
			
			if(e11 >= e12 || e11 >= e21 || e12 >= e22 || e21 >= e22)
			{
				print "Impossible";
				return;
			}
		}
		
		forn1(i, n)
		forn1(j, m)
		{
			ll e11 = m2[i - 1][j - 1];
			ll e12 = m2[i - 1][j];
			ll e21 = m2[i][j - 1];
			ll e22 = m2[i][j];
			
			if(e11 >= e12 || e11 >= e21 || e12 >= e22 || e21 >= e22)
			{
				print "Impossible";
				return;
			}
		}

		print "Possible";
	}
};
