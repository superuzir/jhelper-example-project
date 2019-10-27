#include <iostream>

#include "../library/lib.hpp"

class AZabivchivost
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll a = read_ll();
		ll b = read_ll();

		if(b - a == 1)
		{
			print a, b;
		}
		else if(a == b)
		{
			print a * 10, b * 10 + 1;
		}
		else if(a == 9 && b == 1)
		{
			print 9, 10;
		}
		else 
		{
			print -1;
		}
	}
};
