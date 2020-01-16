#include <iostream>

#include "../library/lib.hpp"

class ASbalansirovannieIzmeneniyaReitinga
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
//		ll __q = read_ll();
		ll __q = 1;

		forn(_, __q){
			ll n = read_ll();
			auto v = read_vll(n);

			ll od = 0;

			forr(vv, v){
				if(vv % 2)
					od++;
			}


		}
	}
};
