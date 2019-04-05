#include <iostream>

#include "../library/lib.hpp"

class CPismo
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		string str = read_s();

		if(all_of(all(str), [](char c){ return isupper(c); }) ||
		   all_of(all(str), [](char c){ return islower(c); }))
		{
			print 0;
			return;
		}
		
		vll up, dw;

		ll up_count = 0;
		ll dw_count = 0;

		for(char c : str)
		{
			if(isupper(c))
			{
				if(up_count)
				{
					dw.pb(0);
					up.pb(up_count);
					up_count = 0;
				}

				dw_count++;
			}
			else
			{
				if(dw_count)
				{
					up.pb(0);
					dw.pb(dw_count);
					dw_count = 0;
				}

				up_count++;
			}
		}

		if(up_count || dw_count)
		{
			dw.pb(dw_count);
			up.pb(up_count);
		}

		ll sum_up = 0;
		ll sum_dw = std::accumulate(all(dw), 0);

		ll ans = max_ll;

		forn(i, up.size())
		{
			ans = min(ans, sum_up + sum_dw);
			
			sum_up += up[i];
			sum_dw -= dw[i];
		}

		ans = min(ans, sum_up + sum_dw);
		
		print ans;
	}
};
