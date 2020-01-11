#include <iostream>

#include "../library/lib.hpp"

class BVirashchivanieDereva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

		soa(v);

		ll kv = accumulate(v.begin(), v.begin() + n / 2, 0ll);
		ll kh = accumulate(v.begin() + n / 2, v.end(), 0ll);

		print kv * kv + kh * kh;
	}
};
