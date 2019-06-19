#include <iostream>

#include "../library/lib.hpp"

class C2EkzamenVBerGUUslozhnennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll vec = read_vll(n);
		vll prev(101);
		ll prev_sum = 0;

		forn(i, n)
		{
			ll fre = m - prev_sum;

			ll ans = 0;

			nfor(j, prev.size())
			{
				ll p = prev[j];

				ll left = vec[i] - fre;
				
				if(left - p * j <= 0)
				{
					ll cnt = (left + j - 1) / j;

					out << ans + cnt << " ";
					break;
				}

				fre += p * j;
				ans += p;
			}

			prev[vec[i]]++;
			prev_sum += vec[i];
		}

		out << endl;
	}
};
