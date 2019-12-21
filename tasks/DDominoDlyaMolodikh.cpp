#include <iostream>

#include "../library/lib.hpp"

class DDominoDlyaMolodikh
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

		ll x = 0, y = 0;
		for (ll i = 0; i < n; i++) {
			swap(x, y);
			
			x += v[i] / 2;
			y += (v[i] + 1) / 2;
		}

		print min(x, y);
	}
};
