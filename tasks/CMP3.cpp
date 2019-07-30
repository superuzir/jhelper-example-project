#include <iostream>

#include "../library/lib.hpp"

class CMP3
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll bytes = read_ll();
		vll vec = read_vll(n);

		ll k = bytes * 8 / n;
		ll span = 1ull << min(k, 31ll);
//		ll span = 1 << k;

//		dbg(span); // [0,span]

		soa(vec);

		multiset<ll> set;

		size_t mx = 0;

		forn(i, n)
		{
			set.insert(vec[i]);

			while(*prev(set.end()) - *set.begin() >= span)
			{
				set.erase(set.begin());
			}

//			dbg(set.size());

			mx = max(mx, set.size());
		}

		print n - mx;
	}
};
