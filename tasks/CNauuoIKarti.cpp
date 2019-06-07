#include <iostream>

#include "../library/lib.hpp"

class CNauuoIKarti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll a = read_vll(n);
		vll b = read_vll(n);

		if(all_of(all(b), [](ll b){return b == 0;}))
		{
			print n;
			return;
		}

		forn(i, n)
		{
			bool sorted = true;
			forlr(j, i, n)
			{
				if(b[j] != 1 + j - i)
				{
					sorted = false;
					break;
				}
			}

			if(b[i] == 1 && sorted)
			{
				bool yeah = true;

				forn(j, i)
				{
					if(b[j] && b[j] - j - 1 <= b.back())
					{
						yeah = false;
						break;
					}
				}

				if(yeah)
				{
					print i;
					return;
				}
			}
		}

		ll ans = 0;

		forn(i, n)
		{
			if (b[i])
			{
				ll f = n + 2 + i - b[i];
				ans = max(ans, f);
			}

			if(a[i])
			{
				ans = max(ans, n - a[i] + 1);
			}
		}

		print ans;
	}
};
