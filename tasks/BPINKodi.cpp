#include <iostream>

#include "../library/lib.hpp"

class BPINKodi
{
	ll change(vs & v, ll i){
		ll n = v.size();

		if(count(all(v), v[i]) == 1)
			return 0;

		forn(p, 4){
			forn(d, 10) {
				string s = v[i];
				s[p] = '0' + d;

				bool ok = true;

				forn(j, n) {
					if (i == j)
						continue;

					if(s == v[j]){
						ok = false;
						break;
					}
				}

				if(ok) {
					v[i] = s;
					return 1;
				}
			}
		}

		return 0;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			ll n = read_ll();
			auto v = read_vs(n);

			ll ans = 0;

			forn(i, n){
				ans += change(v, i);
			}

			print ans;
			forr(vv, v)
				print vv;
		}
	}
};
