#include <iostream>

#include "../library/lib.hpp"

class DGarbageDisposal
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);


		ll ans = 0;
		ll left = 0;

		forn(i, n)
		{
			if(!left)
			{
				left = vec[i];
				left -= (vec[i] / k) * k;
				ans += vec[i] / k;
			}
			else
			{
				ll free_space = k - left;

				if(vec[i] < free_space)
				{
					left = 0;
					ans++;
				}
				else
				{
					vec[i] += left;
					ans += vec[i] / k;
					left = vec[i] % k;
				}
			}
		}
		
		if(left)
			ans++;

		print ans;
	}
};
