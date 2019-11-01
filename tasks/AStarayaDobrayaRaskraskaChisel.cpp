#include <iostream>

#include "../library/lib.hpp"

class AStarayaDobrayaRaskraskaChisel
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q){
			if(gcd(read_ll(), read_ll()) == 1)
				print "Finite";
			else
				print "Infinite";
		}
	}
};
