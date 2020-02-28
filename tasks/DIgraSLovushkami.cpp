#include <iostream>

#include "../library/lib.hpp"

class DIgraSLovushkami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll m = read_ll();
		ll n = read_ll();
		ll k = read_ll();
		ll t = read_ll();

		auto a = read_vll(m);

		soa(a);

		vvll d;

		forn(i, k){
			vll dd(3);

			ll li = read_ll() - 1;
			ll ri = read_ll() - 1;
			ll di = read_ll();

			d.pb({li, +1, di});
			d.pb({ri, -1, di});
		}

		soa(d);

		ll l = 1;
		ll r = m + 1;

//		dbg(a);
//		dbg(d);

		ll ans = 0;

		while(l < r){
			ll mid = (l + r) / 2;

			ll smel = a[m - mid];

//			dbg(l, mid, r, smel);

			vll rng(n + 1, 1);

			ll clov = 0;

			forn(i, d.size() - 1){
				if(smel < d[i][2]){
					clov += d[i][1];
				}

				if(clov)
					forlr(j, d[i][0], d[i + 1][0] + 1)
						rng[j] = 3;

//				dbg(clov, rng, d[i]);
			}


//			dbg(sua(rng), t);

			if(sua(rng) > t){
				r = mid;
			} else {
				l = mid + 1;
				ans = max(ans, mid);
			}
		}

		print ans;
	}
};
