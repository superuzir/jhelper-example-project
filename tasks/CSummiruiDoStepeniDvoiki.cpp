#include <iostream>

#include "../library/lib.hpp"
#include "../library/bit.h"

class CSummiruiDoStepeniDvoiki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		multiset<ll> set;
		ll ans = 0;
		
		forr(v, vec)
			set.insert(v);

		for(auto it = set.begin(); it != set.end();)
		{
			ll val = *it;
			it = set.erase(it);

			bool found = false;
			
			for(ll p2 = nextPowerOf2(val); p2 < 10e11; p2 = nextPowerOf2(p2 + 1))
			{
				if(set.count(p2 - val))
				{
					found = true;
					break;
				}
			}
			
			if(found)
				it = ++set.insert(val);
			else
				ans++;
		}

		print ans;
	}
};
