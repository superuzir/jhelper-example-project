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
			
			auto bit = lower_bound(all(b), a[k1] + ta);
			
			if(b.end() - bit <= k2)
			{
				print -1;
				return;
			}
			
			ans = max(ans, *(bit + k2) + tb);
		}
		
		print ans;
	}
};
