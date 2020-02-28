#include <iostream>

#include "../library/lib.hpp"
#include "../library/matrix.h"
#include "../library/itersame.h"

class EPoluchiPerestanovku
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		auto v = read_mll(n, m);

		ll ans = 0;

		forn(j, m){
			vll col(2 * n);

			forn(i, n){
				col[i] = col[i + n] = v[i][j];
			}

			forn(i, 2 * n){
				col[i] -= i * m + j + 1;
			}

			ll mx = 0;

			itersameall(col, {
				mx = max(mx, ll(e - b));
			});

			ll sh = n;

			itersameall(col, {
				ll i = (b - col.begin()) % n;

				ll exp = i * m + j + 1;
				ll act = v[i][j];


				if(mx == ll(e - b)){
//					dbg(i, j, exp, act);
					if(act % m == (j + 1) % m)
						sh = min(sh, ((exp - act) / m + n) % n);
				}
			});

//			dbg(j, mx, sh);

			ans += min(n - mx + sh, n);
		}

		print ans;
	}
};
