#include <iostream>

#include "../library/lib.hpp"

class BKamenNozhniciBumagaSOgranicheniyami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll r = read_ll();
			ll p = read_ll();
			ll s = read_ll();

			auto str = read_s();

			ll r1 = count(all(str), 'R');
			ll p1 = count(all(str), 'P');
			ll s1 = count(all(str), 'S');

			if(min(r, s1) + min(p, r1) + min(s, p1) >= n / 2 + n % 2) {
				print "YES";

				string ans(str.size(), '-');

				forn(i, n){
					if(str[i] == 'R' && p){ p--; ans[i] = 'P'; }
					if(str[i] == 'P' && s){ s--; ans[i] = 'S'; }
					if(str[i] == 'S' && r){ r--; ans[i] = 'R'; }
				}

				forn(i, n){
					if(ans[i] == '-'){
						if(p) { p--; ans[i] = 'P'; }
						else if(s) { s--; ans[i] = 'S'; }
						else if(r) { r--; ans[i] = 'R'; }
					}
				}

				print ans;
			} else {
				print "NO";
			}
		}
	}
};
