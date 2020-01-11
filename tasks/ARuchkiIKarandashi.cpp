#include <iostream>

#include "../library/lib.hpp"

class ARuchkiIKarandashi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			ll a = read_ll();
			ll b = read_ll();
			ll c = read_ll();
			ll d = read_ll();
			ll k = read_ll();

			ll k1 = divceil(a, c);
			ll k2 = divceil(b, d);

			if (k1 + k2 <= k) {
				print k1, k2;
			} else {
				print -1;
			}
		}
	}
};
