#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class DABStroka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto s = read_s();

		vll v;

		itersameall(s, { v.pb(e - b); });

		ll ans = 0;

		forn1(i, v.size())
			ans += v[i - 1] + v[i] - 1;

		print n * (n - 1) / 2 - ans;
	}
};
