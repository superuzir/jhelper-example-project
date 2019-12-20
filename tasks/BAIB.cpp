#include <iostream>

#include "../library/lib.hpp"

class BAIB
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

			ll s = 0;
			ll ans = 0;

			while(s < d || s % 2 != d % 2){
				ans++;
				s += ans;
			}

			print ans;
		}
	}
};
