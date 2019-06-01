#include <iostream>

#include "../library/lib.hpp"

class BBornThisWay
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll ta = read_ll();
		ll tb = read_ll();
		ll k = read_ll();
		vll a = read_vll(n);
		vll b = read_vll(m);

		if(k >= n || k >= m)
		{
			print -1;
			return;
		}

		ll ans = 0;
		
		forn(k1, k + 1)
		{
			ll k2 = k - k1;
			
			ll amax = a[k1] + ta;
			
			auto bit = lower_bound(all(b), amax);
			
			if(bit == b.end())
			{
				print -1;
				return;
			}
			
			ans = max(ans, *(bit + k2));
			
//			print k1, k2, ":", amax, ans;
		}
		
		print ans + tb;
	}
};
