#include <iostream>

#include "../library/lib.hpp"

class ANakleikiIIgrushki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(i, q)
		{
			ll n = read_ll();
			ll s = read_ll();
			ll t = read_ll();

			if(s == n)
			{
				print n - t + 1;
			}
			else if(t == n)
			{
				print n - s + 1;
			}
			else
			{
				print n - min(s, t) + 1;
			}
		}
	}
};
