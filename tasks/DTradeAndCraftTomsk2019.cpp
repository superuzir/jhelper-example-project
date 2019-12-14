#include <iostream>

#include "../library/lib.hpp"

class DTradeAndCraftTomsk2019
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll a = read_ll();
		ll b = read_ll();
		ll c = read_ll();
		ll d = read_ll();

		ll x = (d * n) / (c * b + d * a);

		ll ans1 = x * b / d;
		ll ans2 = (n - (x + 1) * a) / c;

		print max(ans1, ans2);
	}
};
