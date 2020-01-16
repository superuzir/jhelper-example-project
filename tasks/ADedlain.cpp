#include <iostream>

#include "../library/lib.hpp"

class ADedlain
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll n = read_ll();
			ll d = read_ll();

			ll x = sqrt(d) - 1;

			bool ok = false;

			forlr(i, max(0ll, x - 5), min(n, x + 5)){
			    if(i + divceil(d, i + 1) <= n)
			        ok = true;
			}

			print ok ? "YES" : "NO";
		}
	}
};
