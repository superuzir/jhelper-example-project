#include <iostream>

#include "../library/lib.hpp"

class BNirvana
{
	ll proizv(ll num)
	{
		string s = to_string(num);
		ll ans = s[0] - '0';

		forn1(i, s.size())
			ans *= s[i] - '0';

		return ans;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		string str = to_string(q);
		
		vll cand;
		cand.pb(q);
		
		forn(i, str.size() - 1)
		{
			string s = str;
			s[i]--;
			for(ll j = i + 1; j < str.size(); j++)
				s[j] = '9';
			
			cand.pb(stoll(s));
		}
		
		ll maxpr = 0;
		
		forn(i, cand.size())
		{
			ll pr = proizv(cand[i]);
			if(pr > maxpr)
			{
				maxpr = pr;
			}
		}
		
		print maxpr;
	}
};
