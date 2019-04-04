#include <iostream>

#include "../library/lib.hpp"

class CDaniDlinaISummaCifr
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll m = read_ll();
		ll s1 = read_ll();

		if(s1 == 0)
		{
			if(m == 1)
				print 0, 0;
			else
				print -1, -1;
			return;
		}

		string min(m, '0');
		string max(m, '0');

		{
			ll s = s1;

			min[0] = '1';
			s--;

			nfor(i, min.size())
			{
				while(s && min[i] != '9')
				{
					min[i]++;
					s--;
				}
			}

			if(s)
			{
				print -1, -1;
				return;
			}
		}

		{
			ll s = s1;

			forn(i, max.size())
			{
				while(s && max[i] != '9')
				{
					max[i]++;
					s--;
				}
			}

			if(s)
			{
				print -1, -1;
				return;
			}
		}
		
		print min, max;
	}
};
