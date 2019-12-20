#include <iostream>

#include "../library/lib.hpp"

class CYagodnoeVarene
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			auto v1 = read_vll(n);
			auto v2 = read_vll(n);

			reverse(all(v2));

			vll r1(n + 1);
			vll r2(n + 1);

			forn1(i, n + 1){
				r1[i] = r1[i - 1] + (v1[i - 1] == 1 ? +1 : -1);
				r2[i] = r2[i - 1] + (v2[i - 1] == 1 ? +1 : -1);
			}

			map<ll, ll> m1;
			map<ll, ll> m2;

			forn(i, n + 1){
				m1[r1[i]] = n - i;
				m2[r2[i]] = n - i;
			}

			ll ans = max_ll;

			forr(mm, m1){
				if(m2.count(-mm.fi)){
					ans = min(ans, mm.se + m2[-mm.fi]);
				}
			}

			print ans;
		}
	}
};
