#include <iostream>

#include "../library/lib.hpp"
#include "../library/setBorrow.h"


class CHoroshiiMassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);
		vll ans;

		multiset<pll> set;

		ll sum = 0;
		
		forn(i, n)
		{
			set.insert({vec[i], i + 1});
			sum += vec[i];
			if(sum > 10e7)
			{
				print 0;
				return;
			}
		}

		setBorrow(set, [&](pll el){
			if(sum - el.fi == 2 * set.rbegin()->fi)
				ans.pb(el.se);
		});

		print ans.size();
		answer(ans, out);
	}

};
