#include <iostream>

#include "../library/lib.hpp"

class AMezoIgraetVZomu
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto s = read_s();

		print 1 + count(all(s), 'L') + count(all(s), 'R');
	}
};
