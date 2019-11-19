#include <iostream>

#include "../library/lib.hpp"

class AIzmenenieGromkosti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll a = read_ll();
			ll b = read_ll();

			ll d = abs(a - b);

			ll ans = d / 5;

			d -= ans * 5;

			switch(d){
				case 4: ans += 2; break;
				case 3: ans += 2; break;
				case 2: ans += 1; break;
				case 1: ans += 1; break;
			}

			print ans;
		}

	}
};
