#include <iostream>

#include "../library/lib.hpp"

class CVozrastayushchayaMatritsa
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = 1;

		forn(_, __q){
			ll n = read_ll();
			ll m = read_ll();

			vvll v(n);

			forn(i, n){
				v[i] = read_vll(m);
			}

			auto v2 = v;

			forn(i, n){
				nfor1(j, m){
					if(v[i][j] == 0){
						v2[i][j] = v2[i][j + 1] - 1;
					}
				}
			}

			forn(j, m){
				nfor1(i, n){
					if(v[i][j] == 0){
						v2[i][j] = min(v2[i][j], v2[i + 1][j] - 1);
					}
				}
			}

			forn(i, n) {
				nfor1(j, m) {
					if(v2[i][j] >= v2[i][j + 1]){
						print -1;
						return;
					}
				}
			}

			forn(j, m) {
				nfor1(i, n) {
					if(v2[i][j] >= v2[i + 1][j]){
						print -1;
						return;
					}
				}
			}

			ll ans = 0;

			forn(i, n){
				ans += sua(v2[i]);
			}

			print ans;
		}
	}
};
