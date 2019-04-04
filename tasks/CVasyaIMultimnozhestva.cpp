#include <iostream>

#include "../library/lib.hpp"

class CVasyaIMultimnozhestva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto vec = read_vll(n);

		vll count(101);

		forn(i, n)
		{
			count[vec[i]]++;
		}

		string ans(n, 'A');

		char c = 'A';

		forn(i, n)
		{
			if(count[vec[i]] == 1)
			{
				ans[i] = c;
				c = c == 'A' ? 'B' : 'A';
			}
		}

		if(c == 'A')
		{
			print "YES";
			print ans;
		}
		else
		{
			forn(i, n)
			{
				if(count[vec[i]] > 2)
				{
					ans[i] = c;
					print "YES";
					print ans;
					return;
				}
			}
			print "NO";
		}
	}
};
