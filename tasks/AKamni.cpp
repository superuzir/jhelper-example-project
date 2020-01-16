#include <iostream>

#include "../library/lib.hpp"

class AKamni
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll a = read_ll();
			ll b = read_ll();
			ll c = read_ll();

			ll ans = min(b, c / 2);
			b -= ans;
			ans += min(a, b / 2);

			print ans * 3;
		}
	}
};
