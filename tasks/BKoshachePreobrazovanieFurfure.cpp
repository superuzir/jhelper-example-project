#include <iostream>

#include "../library/lib.hpp"

class BKoshachePreobrazovanieFurfure
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll x = read_ll();
		
		vll ans;
		ll inc_cnt = 0;
		
		bool inc = false;

		nfor(i, 31)
		{
			if((x & (x + 1)) == 0)
			{
				print ans.size() + inc_cnt;
				
				forn(a, ans.size())
				{
					out << ans[a] << ' ';
				}
				
				return;
			}

			if(inc)
			{
				x++;
				i++;
				inc_cnt++;
				inc = false;
			}
			else if((x & (1 << i)) == 0 && (x & (1 << (i + 1))) != 0) 
			{
				x ^= (1 << (i + 1)) - 1;
				ans.pb(i + 1);
				inc = true;
			}
		}
		
		print ans.size() + inc_cnt;

		forn(a, ans.size())
		{
			out << ans[a] << ' ';
		}
	}
};
