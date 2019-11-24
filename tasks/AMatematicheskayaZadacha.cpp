#include <iostream>

#include "../library/lib.hpp"

class AMatematicheskayaZadacha
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			auto v = read_vpll(n);

			ll mn = max_ll;
			ll mx = 0;
			
			forr(e, v){
				mx = max(mx, e.fi);
				mn = min(mn, e.se);
			}
			
			if(mx < mn)
				mx = mn;
			
			print mx - mn;
		}
	}
};
