#include <iostream>

#include "../library/lib.hpp"

class DRazdelenieMassiva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);

		vll dp(n + 1);

		nfor(i, n)
		{
			dp[i] = dp[i + 1] + vec[i];
		}

		if(k == 1)
		{
			print dp[0];
			return;
		}

		vpll ps;

		forn1(i, n)
		{
			ps.pb({dp[i], i});
		}

		sort(rall(ps), by(fi));

		ps.resize(k - 1);

		sort(rall(ps), by(se));

//		print ps;
//		print dp;

		ll ans = ps[0].fi * k;

//		print ans;

		forn1(i, k - 1)
		{
			ans += (ps[i].fi - ps[i - 1].fi) * (k - i);
		}

		ans += dp[0] - ps.back().fi;

//		print ans, dp;

		print ans;
	}
};
