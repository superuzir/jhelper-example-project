#include <iostream>

#include "../library/lib.hpp"

class CMP3
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll span = 1ull << min(read_ll() * 8 / n, 60ll);
		vll vec = read_vll(n);

		soa(vec);

		map<ll, ll> map;

//		dbg(span);

		size_t cnt = 0;
		size_t mx = 0;

		forn(i, n)
		{
			map[vec[i]]++;
			cnt++;

			while(map.size() > span)
			{
				cnt -= map.begin()->se;
				map.erase(map.begin());
			}

//			dbg(i, vec[i], cnt, map);

			mx = max(cnt, mx);
		}

		print n - mx;
	}
};
