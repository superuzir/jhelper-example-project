#include <iostream>

#include "../library/lib.hpp"

class BBolsheGlasnih
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll k = read_ll();

		forn1(n, k)
		{
			if(k % n == 0)
			{
				ll m = k / n;

				if(m >= 5 && n >= 5)
				{
					string ans;
					
					forn(i, m * n)
					{
						ll r = i / m;
						ll c = i % n;
						ans += "aeoiu"[(c + r) % 5];
					}
					
					print ans;

					return;
				}
			}
		}

		print -1;
	}
};
