#include <iostream>

#include "../library/lib.hpp"

class CSonyaIRoboti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		vll dpr(n, 1);

		{
			vll cnt(1e5 + 1, 0);
			cnt[vec[n-1]] = 1;
			
			nfor1(i, n)
			{
				dpr[i] = dpr[i + 1] + (cnt[vec[i]] == 0);
				cnt[vec[i]]++;
			}
		}

		ll ans = 0;

		{
			vll cnt(1e5 + 1, 0);

			forn(i, n - 1)
			{
				if(cnt[vec[i]] == 0)
				{
					ans += dpr[i + 1];
				}

				cnt[vec[i]]++;
			}
		}

		print ans;
	}
};
