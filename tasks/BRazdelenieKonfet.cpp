#include <iostream>

#include "../library/lib.hpp"

class BRazdelenieKonfet
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q){
			ll n = read_ll();
			ll k = read_ll();

			ll ans = (n / k) * k;

			ans += min(k / 2, n % k);

			print ans;
		}
	}
};
