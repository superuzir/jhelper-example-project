#include <iostream>

#include "../library/lib.hpp"

class CViVseUzhePobediteli
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			ll n = read_ll();

			vll ans(1);

			for(ll i = 1; i * i <= n; i++){
				ans.pb(i);
				ans.pb(n / i);
			}

			soa(ans);

			ans.resize(unique(all(ans)) - ans.begin());

			print ans.size();
			answer(ans, out);
		}
	}
};
