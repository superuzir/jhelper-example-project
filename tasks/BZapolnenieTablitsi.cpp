#include <iostream>

#include "../library/lib.hpp"

const ll MOD = 1000000007;

class BZapolnenieTablitsi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = 1;

		forn(_, __q){
			ll h = read_ll();
			ll w = read_ll();
			auto r = read_vll(h);
			auto c = read_vll(w);

			vector<vb> v(h + 1, vb(w + 1));

			forn(i, h){
				forn(j, r[i]){
					v[i][j] = true;
				}
			}

			forn(j, w){
				forn(i, c[j]){
					v[i][j] = true;
				}
			}

			bool ok = true;

			forn(i, h){
				forn(j, r[i]){
					if(!v[i][j])
						ok = false;
				}

				if(v[i][r[i]])
					ok = false;
			}

			forn(j, w){
				forn(i, c[j]){
					if(!v[i][j])
						ok = false;
				}

				if(v[c[j]][j])
					ok = false;
			}

			if(!ok) {
				print 0;
				return;
			}

			forn(i, h){
				v[i][r[i]] = true;
			}

			forn(j, w){
				v[c[j]][j] = true;
			}

			ll ans = 1;

			forn(i, h) {
				forn(j, w) {
					if(!v[i][j]) {
						ans *= 2;
						ans %= MOD;
					}
				}
			}

			print ans;
		}
	}
};
