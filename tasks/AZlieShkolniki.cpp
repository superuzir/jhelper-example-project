#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class AZlieShkolniki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q){
			ll k = read_ll();
			auto s = read_s();

			ll ans = 0;
			bool fl = false;

			itersameall(s, {
				if(*b == 'A')
					fl = true;

				if(fl && *b == 'P')
					ans = max(ans, ll(e - b));
			});

			print ans;
		}
	}
};
