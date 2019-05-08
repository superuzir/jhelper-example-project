#include <iostream>

#include "../library/lib.hpp"

class CObmenSosednihElementov
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);
		string str = read_s();

		vll down(n, -1);
		vll up(n, -1);

		ll to = 0;

		forn(i, n)
		{
			down[i] = to;

			if(str[i] == '0' || i == n - 1)
			{
				forn(j, to + 1)
					up[i - to + j] = to - j;

				to = 0;
			}
			else
				to++;
		}

		forn(i, n)
		{
			ll src = i;
			ll dst = vec[i] - 1;
			
			if((dst > src && dst - src > up[i]) || (dst < src && src - dst > down[i]))
			{
				print "NO";
				return;
			}
		}
		
		print "YES";
	}
};
