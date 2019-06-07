#include <iostream>

#include "../library/lib.hpp"

class ANauuoIGolosa
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll x = read_ll();
		ll y = read_ll();
		ll z = read_ll();

		ll dif = x - y;

		if(abs(dif) > z || z == 0)
		{
			if(dif > 0)
				print "+";
			else if(dif < 0)
				print "-";
			else
				print 0;
		}
		else
		{
			print "?";
		}
	}
};
