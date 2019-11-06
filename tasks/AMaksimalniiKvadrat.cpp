#include <iostream>

#include "../library/lib.hpp"

class AMaksimalniiKvadrat
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			auto v = read_vll(n);

			sort(rall(v));

			ll ans = 0;

			forn(i, n){
				if(v[i] >= i + 1)
					ans = i + 1;
			}

			print ans;
		}
	}
};
