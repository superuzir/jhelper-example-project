#include <iostream>

#include "../library/lib.hpp"

class BKomnatiILestnitsi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			ll n = read_ll();
			auto s = read_s();

			ll l = 0; forn(i, n){ if(s[i] == '0') l++; else break; }
			ll r = 0; nfor(i, n){ if(s[i] == '0') r++; else break; }

			print count(all(s), '1') == 0 ? n : 2 * (n - min(l, r));
		}
	}
};
