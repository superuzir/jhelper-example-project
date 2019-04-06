#include <iostream>

#include "../library/lib.hpp"

class CStepeniDvoiki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		vll ans;

		forn(i, 32)
		{
			if(n & (1 << i))
				ans.pb(1 << i);
		}
		
		if(ans.size() > k || k > n)
		{
			print "NO";
		}
		else
		{
			print "YES";
			
			sort(all(ans));
			
			while(ans.size() < k)
			{
				nfor(i, ans.size())
				{
					if(ans[i] != 1)
					{
						ll cand = ans[i];
						ans.erase(ans.begin() + i);
						ans.pb(cand / 2);
						ans.pb(cand / 2);
						break;
					}
				}
			}

			sort(all(ans));

			answer(ans, out);
		}
	}
};
