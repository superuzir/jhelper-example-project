#include <iostream>

#include "../library/lib.hpp"
#include "../library/bit.h"

class BNovogodnyayaNoch
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		print k == 1 ? n : nextPowerOf2(n + 1) - 1;
	}
};
