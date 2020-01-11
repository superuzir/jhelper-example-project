#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class DABStroka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_s();

		vll l;

		itersameall(v, {
			l.pb(e - b);
		});

		ll ans = n * (n + 1) / 2 - n;

		forn1(i, l.size()){
			ans -= l[i - 1] + l[i] - 1;
		}

		print ans;
	}
};
