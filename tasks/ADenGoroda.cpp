#include <iostream>

#include "../library/lib.hpp"

class ADenGoroda
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll x = read_ll();
		ll y = read_ll();

		vll a = read_vll(n);
		
		forn(i, n)
		{
			ll i1 = max(0ll, i - x);
			ll i2 = min(n, i + y + 1);
			
			auto it1 = min_element(a.begin() + i1, a.begin() + i);
			auto it2 = min_element(a.begin() + i + 1, a.begin() + i2);
			
			bool c1 = it1 == a.begin() + i || a[i] < *it1;
			bool c2 = it2 == a.begin() + i2 || a[i] < *it2;
			
			if(c1 && c2)
			{
				print i + 1;
				return;
			}
		}
	}
};
