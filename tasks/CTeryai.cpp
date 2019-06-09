#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class CTeryai
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vll dp(50, 0);

		vll t = {4,8,15,16,23,42};
		
		forn(i, n)
		{
			ll v = read_ll();

			if(v == 4)
				dp[v]++;
			else
			{
				ll prev = find(all(t), v) - t.begin() - 1;
				
				dp[v] = min(dp[v] + 1, dp[t[prev]]);
			}
		}
		
		print n - 6 * dp[42];
	}
};
