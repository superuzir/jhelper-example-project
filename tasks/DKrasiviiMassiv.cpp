#include <iostream>

#include "../library/lib.hpp"

class DKrasiviiMassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll x = read_ll();
		auto v = read_vll(n);

		ll ans = 0;
		ll dp1 = 0;
		ll dp2 = 0;
		ll dp3 = 0;

		forr(a, v){
			dp1 = max(0ll, dp1 + a);
			dp2 = max(dp2 + a * x, dp1);
			dp3 = max(dp3 + a, dp2);
			ans = max(ans, dp3);
		}

		print ans;
	}
};
