#include <iostream>

#include "../library/lib.hpp"

class B2KoshachyaVecherinkaUslozhnennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		vll col(100*1000+10);
		map<ll, ll> cnts;

		ll ans = 1;

		forn(i, n)
		{
			ll c1 = col[vec[i]];
			cnts[c1]--;

			if(cnts[c1] == 0)
				cnts.erase(c1);

			col[vec[i]]++;
			ll c2 = col[vec[i]];

			cnts[c2]++;

			if(cnts.size() == 2)
			{
				if(cnts.count(1) || cnts.rbegin()->se == 1)
					ans = max(ans, i + 1);
			}
			else if(cnts.size() == 3)
			{
				if(cnts.count(1) && cnts[1] == 1)
				{
					ans = max(ans, i + 1);
				}
				else
				{
					auto it = cnts.begin();

					auto c1 = *++it;
					auto c2 = *++it;

					if(c2.se == 1 && c1.fi + 1 == c2.fi)
					{
						ans = max(ans, i + 1);
					}
				}
			}
		}

		print ans;
	}
};
