#include <iostream>

#include "../library/lib.hpp"

class C1EkzamenVBerGUUproshennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll vec = read_vll(n);

		forn(i, n)
		{
			vll prev(vec.begin(), vec.begin() + i);

			sort(rall(prev));

			ll sum = accumulate(all(prev), 0ll);

			bool ok = false;

			forn(j, prev.size())
			{
				ll p = prev[j];

				if(m - sum >= vec[i])
				{
					out << j << " ";
					ok = true;
					break;
				}

				sum -= p;
			}

			if(!ok)
				out << prev.size() << " ";
		}

		out << endl;
	}
};
