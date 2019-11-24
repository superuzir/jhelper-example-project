#include <iostream>

#include "../library/lib.hpp"

class EDvaMassivaISummaFunktsii
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll MOD2 = 998244353;

		ll n = read_ll();
		auto a = read_vll(n);
		auto b = read_vll(n);

		forn(i, n){
			a[i] *= (i + 1) * (n - i);
		}

		sort(all(a));
		sort(rall(b));

		ll ans = 0;

		forn(i, n){
			ans += ((a[i] % MOD2) * b[i]) % MOD2;
			ans %= MOD2;
		}

		print ans;
	}
};
