#include <iostream>

#include "../library/lib.hpp"

class ASashaINemnogoOtdiha
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);
				
		map<ll, pll> map;

		ll xr = vec[0];
		map[xr].fi++;
		map[0].se++;
		
		ll ans = 0;
		
		forn1(i, n)
		{
			xr ^= vec[i];
			
			if(map.count(xr))
			{
				if(i % 2 == 0)
					ans += map[xr].fi;
				else
					ans += map[xr].se;
			}

//			dbg(i, xr, ans);
			
			if(i % 2 == 0)
				map[xr].fi++;
			else
				map[xr].se++;
		}
		
		print ans;
	}
};
