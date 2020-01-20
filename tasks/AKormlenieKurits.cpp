#include <iostream>

#include "../library/lib.hpp"

class AKormlenieKurits
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		string tbl;

		forn(i, 10) tbl += '0' + i;
		forn(i, 26) tbl += 'a' + i;
		forn(i, 26) tbl += 'A' + i;

		forn(_, __q){
			ll r = read_ll();
			ll c = read_ll();
			ll k = read_ll();

			auto v = read_vs(r);

			ll ric = 0;

			forr(s, v){
				ric += count(all(s), 'R');
			}

			vll kur(k, ric/k);

			forn(i, ric % k){
				kur[i]++;
			}

			ll ans = 0;

			forn(i, r){
				forn(jj, c){
					ll j = i % 2 ? c - jj - 1 : jj;

					if(v[i][j] == 'R'){
						v[i][j] = tbl[ans];
						kur.back()--;
						if(kur.back() == 0){
							kur.pop_back();
							if(kur.size())
								ans++;
						}
					} else {
						v[i][j] = tbl[ans];
					}
				}
			}

			forr(s, v){
				print s;
			}
		}
	}
};
