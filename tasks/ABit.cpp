#include <iostream>

#include "../library/lib.hpp"

class ABit
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n; in >> n;

		ll x = 0;

		forn(i, n)
        {
		    string s; in >> s;
            x += s[1] == '+' ? 1 : -1;
        }

		print x;
	}
};
