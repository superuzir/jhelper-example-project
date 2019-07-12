#include <iostream>

#include "../library/lib.hpp"

class ATokitsukazeIUluchshenie
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		n %= 4;
		
		if(n == 0) print 1, "A";
		if(n == 1) print 0, "A";
		if(n == 2) print 1, "B";
		if(n == 3) print 2, "A";
	}
};
