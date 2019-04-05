#include <iostream>

#include "../library/lib.hpp"

class BPingvinPoloIMatrica
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll d = read_ll();
		vll vec = read_vll(m * n);

		sort(all(vec));

		ll first = vec[0];
		
		forn(i, n * m)
		{
			vec[i] -= first;
			
			if(vec[i] % d)
			{
				print -1;
				return;
			}
			else
			{
				vec[i] /= d;
			}
		}
		
		ll ans = 0;

		if(vec.size() % 2 == 1)
		{
			ll median = vec[vec.size() / 2];

			forn(i, n * m)
				ans += abs(vec[i] - median);
		}
		else
		{
			ll median1 = vec[vec.size() / 2 - 1];
			ll median2 = vec[vec.size() / 2];

			forn(i, n * m / 2)
				ans += abs(vec[i] - median1);

			for(int i = n * m / 2; i < n * m; i++)
				ans += abs(vec[i] - median2);

			ans += (median2 - median1) * n * m / 2;
		}

		print ans;
	}
};
