#include <iostream>

#include "../library/lib.hpp"

class B1ObmenKnigamiProstayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			auto vec = read_vll(n);

			vll ans;

			forn(i, n){
				ll cur = vec[i] - 1;

				ll c = 0;

				while(i != cur){
					cur = vec[cur] - 1;
					c++;
				}

				ans.pb(c + 1);
			}

			answer(ans, out);
		}
	}
};
