#include <iostream>

#include "../library/lib.hpp"

class DSdelaemZaborVelikimSnova
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			auto v = read_vpll(n);

			auto dp = vector(3, vll(n));

			dp[0][0] = 0;
			dp[1][0] = 1 * v[0].se;
			dp[2][0] = 2 * v[0].se;

			forn1(i, n){
				if(v[i].fi == v[i - 1].fi)
				{
					dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]);
					dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
					dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
				}
				else if(v[i].fi == v[i - 1].fi + 1)
				{
					dp[0][i] = min(dp[0][i - 1], dp[2][i - 1]);
					dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]);
					dp[2][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
				}
				else if(v[i].fi == v[i - 1].fi + 2)
				{
					dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]);
					dp[1][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
					dp[2][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
				}
				else if(v[i].fi == v[i - 1].fi - 1)
				{
					dp[0][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
					dp[1][i] = min(dp[1][i - 1], dp[2][i - 1]);
					dp[2][i] = min(dp[0][i - 1], dp[2][i - 1]);
				}
				else if(v[i].fi == v[i - 1].fi - 2)
				{
					dp[0][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
					dp[1][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
					dp[2][i] = min(dp[1][i - 1], dp[2][i - 1]);
				}
				else
				{
					dp[0][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
					dp[1][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
					dp[2][i] = min3(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
				}

				dp[1][i] += v[i].se;
				dp[2][i] += v[i].se * 2;
			}

			print min3(dp[0].back(), dp[1].back(), dp[2].back());
		}
	}
};
