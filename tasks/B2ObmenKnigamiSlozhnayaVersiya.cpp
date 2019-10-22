#include <iostream>

#include "../library/lib.hpp"

class B2ObmenKnigamiSlozhnayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			auto vec = read_vll(n);
			vll idx(n, -1);

			vll ans(n, 1);
			
			ll c2 = 0;

			forn(i, n){
				ll cur = vec[i] - 1;
				
				if(idx[cur] != -1)
					continue;

				idx[cur] = c2;

				ll c = 0;

				for(ll cur2 = cur; i != cur2; ){
					idx[cur2] = c2;
					cur2 = vec[cur2] - 1;
					c++;
				}

				for(ll cur2 = cur; i != cur2; ){
					cur2 = vec[cur2] - 1;
					ans[cur2] = c + 1;
				}
				
//				ans.pb(c + 1);
				

				c2++;
			}

			answer(ans, out);
		}
	}
};
