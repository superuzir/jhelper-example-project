#include <iostream>

#include "../library/lib.hpp"

class DKrasiviiMassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll x = read_ll();
		vll vec = read_vll(n);
		vll vec2 = vec;

		if(x < 0)
		{
			forn(i, n)
			{
				vec2[i] *= -1;
			}
		}

//		print vec2;

		{
			vpll dp(n);

			ll count_good = vec2[0] > 0 ? 1 : 0;

			dp[0] = {max(vec2[0], 0ll), count_good };


			forn1(i, n)
			{
				if (dp[i - 1].first + vec2[i] < 0)
				{
					count_good = 0;
					dp[i] = {0, count_good};
				}
				else
				{
					dp[i] = {dp[i - 1].first + vec2[i], count_good++};
				}
			}

			auto it = max_element(all(dp));

//			print dp;
//			print *it;

			if (it->first > 0)
			{
				ll to = it - dp.begin();
				ll from = to - it->second;

				forn(i, n)
				{
					if (i >= from && i <= to)
						vec[i] *= x;
				}

//				print from, to;
			}
		}

//		print vec;

		vll dpans(n);

		dpans[0] = max(vec[0], 0ll);

		forn1(i, n)
		{
			dpans[i] = max(dpans[i - 1] + vec[i], 0ll);
		}

//		print dpans;

		print *max_element(all(dpans));
	}
};
