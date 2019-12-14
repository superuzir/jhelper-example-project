#include <iostream>

#include "../library/lib.hpp"

class ACraftTomsk2019
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll a = read_ll();
		ll b = read_ll();
		ll c = read_ll();
		ll d = read_ll();

		print min(a / c, b / d);
	}
};
