#include <iostream>

#include "../library/lib.hpp"

const ll MOD = 998244353;

class EDvaMassivaISummaFunktsii
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
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
			ans += (a[i] % MOD) * b[i];
			ans %= MOD;
		}

		print ans;
	}
};
