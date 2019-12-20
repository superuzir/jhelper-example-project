#include <iostream>

#include "../library/lib.hpp"

class EKosmicheskiiSoliter
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto a = read_vll(n);

		ll q = read_ll();

		ll ans = sua(a);

		map<pll, ll> m;

		forn(_, q){
			ll s = read_ll();
			ll t = read_ll();
			ll u = read_ll();

			if(m.count({s, t})){
				a[m[{s, t}] - 1]++;

				if(a[m[{s, t}] - 1] > 0)
					ans++;

				m.erase({s, t});
				if(u)
				{
					m[{s, t}] = u;
					a[u - 1]--;
					
					if(a[u - 1] >= 0)
						ans--;
				}
			} else {
				if(u)
				{
					m[{s, t}] = u;
					a[u - 1]--;

					if(a[u - 1] >= 0)
						ans--;
				}
			}
			
			print ans;
		}
	}
};
