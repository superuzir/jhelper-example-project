#include <iostream>

#include "../library/lib.hpp"

class BEksponat
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll vec = read_vll(n);

		sort(rall(vec));

		ll cur = vec[0];

		ll ans = 0;

		forn(i, n - 1)
		{
			if(cur == 1)
			{
				ans += vec[i] - 1;
			}
			else
			{
				if(cur <= vec[i])
				{
					ans += vec[i] - 1;
					cur--;
				}

				if(vec[i + 1] < cur)
				{
					ans -= cur - vec[i + 1];
					cur = vec[i + 1];
				}
			}
		}

		ans += vec.back() - cur;

		print ans;
	}
};
