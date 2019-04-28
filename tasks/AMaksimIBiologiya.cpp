#include <iostream>

#include "../library/lib.hpp"

class AMaksimIBiologiya
{
	ll distance(string str)
	{
		string tgt = "ACTG";

		ll ans = 0;

		forn(i, 4)
		{
			ll dif;
			
			if(tgt[i] > str[i])
				dif = tgt[i] - str[i];
			else
				dif = str[i] - tgt[i];
			
			if(dif > 13)
				ans += 26 - dif;
			else
				ans += dif;
			
		}

		return ans;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		string str = read_s();

		ll ans = max_ll;

		forn(i, n - 3)
		{
			string sub = str.substr(i, 4);
			ans = min(ans, distance(sub));
		}
		
		print ans;
	}
};
