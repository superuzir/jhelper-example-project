#include <iostream>

#include "../library/lib.hpp"

class AFotografiyaNeba
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(2 * n);

		sort(all(vec));

		ll ans = (vec[n - 1] - vec[0]) * (vec[2 * n - 1] - vec[n]);

		forn1(i, n)
			ans = min(ans, (vec[2 * n - 1] - vec[0]) * (vec[i + n - 1] - vec[i]));

		print ans;
	}
};
