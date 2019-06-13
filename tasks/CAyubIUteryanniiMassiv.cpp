#include <iostream>

#include "../library/lib.hpp"

class CAyubIUteryanniiMassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll l = read_ll();
		ll r = read_ll();

		vector<vll> dp(3, vll(n));

		if(r - l < 20)
		{
			forlr(i, l, r + 1)
			{
				dp[i % 3][0]++;
			}
		}
		else
		{
			ll tl = l;
			while(tl % 3 != 0)
			{
				dp[tl % 3][0]++;
				tl++;
			}

			ll tr = r;
			while(tr % 3 != 2)
			{
				dp[tr % 3][0]++;
				tr--;
			}

			ll c = (tr - tl + 1) / 3;
			
			dp[0][0] += c;
			dp[1][0] += c;
			dp[2][0] += c; 
		}

		forn1(i, n)
		{
			dp[0][i] = (dp[0][i - 1] * dp[0][0] + dp[1][i - 1] * dp[2][0] + dp[2][i - 1] * dp[1][0]) % MOD;
			dp[1][i] = (dp[0][i - 1] * dp[1][0] + dp[1][i - 1] * dp[0][0] + dp[2][i - 1] * dp[2][0]) % MOD;
			dp[2][i] = (dp[0][i - 1] * dp[2][0] + dp[1][i - 1] * dp[1][0] + dp[2][i - 1] * dp[0][0]) % MOD;
		}

		print dp[0].back();
	}
};
