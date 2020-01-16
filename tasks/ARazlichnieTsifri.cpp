#include <iostream>

#include "../library/lib.hpp"

class ARazlichnieTsifri
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = 1;

		forn(_, __q){
			ll l = read_ll();
			ll r = read_ll();

			forlr(i, l, r + 1){
				auto s = to_string(i);

				soa(s);

				ll l1 = s.size();

				s.resize(unique(all(s)) - s.begin());

				ll l2 = s.size();

				if(l1 == l2){
					print i;
					return;
				}
			}

			print -1;
		}
	}
};
