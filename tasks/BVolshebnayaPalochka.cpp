#include <iostream>

#include "../library/lib.hpp"

class BVolshebnayaPalochka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			ll x = read_ll();
			ll y = read_ll();

			if(x == 1 && y > 1) print "NO";
			else if(x == 2 && y > 3) print "NO";
			else if(x == 3 && y > 3) print "NO";
			else print "YES";
		}
	}
};
