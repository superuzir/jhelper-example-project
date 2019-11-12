#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


ll MOD2 = 998244353;

ll fac(ll n){
	ll ans = 1;

	forlr(i, 2, n + 1){
		ans *= i;
		ans %= MOD2;
	}

	return ans;
}


class DKolichestvoPerestanovok
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vpll(n);

		ll c1 = 1;
		ll c2 = 1;
		ll c12 = 1;

		sort(all(v));
		itersame(all(v), [&](auto b, auto e){
			c1 *= fac(e - b);
			c1 %= MOD2;
		}, eq(fi));

		itersame(all(v), [&](auto b, auto e){
			c12 *= fac(e - b);
			c12 %= MOD2;
		});

		ll cs = is_sorted(all(v), by(se));

		sort(all(v), by(se));
		itersame(all(v), [&](auto b, auto e){
			c2 *= fac(e - b);
			c2 %= MOD2;
		}, eq(se));

//		dbg(fac(n), c1, c2, c12, cs);

		ll ans = fac(n);

		ans += MOD2 - c1;
		ans += MOD2 - c2;

		if(cs)
			ans += c12;

		ans %= MOD2;

		print ans;
	}
};
