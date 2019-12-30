#include <iostream>

#include "../library/lib.hpp"

class CStopkaPodarkov
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll m = read_ll();

			auto a = read_vll(n);
			auto b = read_vll(m);

			map<ll, ll> map;

			forn(i, n){
				map[a[i]] = i;
			}

			ll mx = -1;

			ll ans = 0;

			forn(i, m){
				ll idx = map[b[i]];

				if(idx > mx){
					ans += (idx - i) * 2 + 1;
				} else {
					ans++;
				}

				mx = max(mx, idx);
			}

			print ans;
		}
	}
};
