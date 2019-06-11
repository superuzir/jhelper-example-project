#include <iostream>

#include "../library/lib.hpp"

class AZapolnenieFormami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		if(n % 2)
		{
			print 0;
		}
		else
		{
			print 1 << n/2;
		}
	}
};
