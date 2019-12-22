#include <iostream>

#include "../library/lib.hpp"

#define checkmax(a,b) do{ a=max((a), (b)); }while(0)

class DOcherednayaZadachaNaPodotrezki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll k = read_ll();

		auto a = read_vll(n);

		vll dp(n + 1);

		ll ans = 0;

		for (ll i = 0; i < n; ++i) {
			dp[i] = a[i] - k;

			ll sum = a[i];

			for (ll j = i - 1; j >= 0 && i - j <= m; --j) {
				checkmax(dp[i], dp[j] + sum - k);
				sum += a[j];
			}

			if (i < m)
				checkmax(dp[i], sum - k);

			checkmax(dp[i], 0ll);
			checkmax(ans, dp[i]);
		}

		print ans;
	}
};
