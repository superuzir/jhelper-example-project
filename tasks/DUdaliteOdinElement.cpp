#include <iostream>

#include "../library/lib.hpp"

class DUdaliteOdinElement
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

		vvll dp(2, vll(n));

		dp[0][0] = 1;
		dp[1][0] = 1;

		forn1(i, n){
			if(v[i - 1] < v[i])
			{
				dp[0][i] = dp[0][i - 1] + 1;
				dp[1][i] = dp[1][i - 1] + 1;
			}
			else
			{
				dp[0][i] = 1;
				dp[1][i] = 1;
			}

			if(i > 1){
				if(v[i - 2] < v[i])
					dp[1][i] = max(dp[1][i], dp[0][i - 2] + 1);
			}
		}

//		dbg(v);
//		dbg(dp[0]);
//		dbg(dp[1]);

		print max(*max_element(all(dp[0])), *max_element(all(dp[1])));
	}
};
