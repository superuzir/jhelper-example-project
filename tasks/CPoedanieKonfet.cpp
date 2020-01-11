#include <iostream>

#include "../library/lib.hpp"

class CPoedanieKonfet
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		auto v = read_vll(n);

		soa(v);

		ll sum = 0;

		vll ans;

		forn(i, n){
			sum += v[i];
			ll j = i - m;
			ans.pb(sum + (j >= 0 ? ans[j] : 0));
		}

		answer(ans, out);
	}
};
