#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

class APrevratitVEdinici
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll x = read_ll();
		ll y = read_ll();
		string s = read_s();

		ll zeros = 0;

		itersame(all(s), [&](auto b, auto e){ if(*b == '0') zeros++; });

		print zeros ? min((zeros - 1) * x + y, zeros * y) : 0;
	}
};
