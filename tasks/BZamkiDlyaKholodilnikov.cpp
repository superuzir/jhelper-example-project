#include <iostream>

#include "../library/lib.hpp"

class BZamkiDlyaKholodilnikov
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll m = read_ll();

			auto a = read_vlli(n);


			if(m < n || n == 2)
			{
				print -1;
			}
			else
			{
				sort(all(a));
				
				ll ans = 0;
				
				vpll p;
				
				forn(i, m - n){
					ans += a[0].fi + a[1].fi;
					p.pb({a[0].se, a[1].se});
				}
				
				forn1(i, n){
					ans += a[i - 1].fi + a[i].fi;
					p.pb({a[i - 1].se, a[i].se});
				}

				ans += a[0].fi + a[n - 1].fi;
				p.pb({a[0].se, a[n - 1].se});
				
				print ans;
				
				forr(pi, p)
					print pi.fi + 1, pi.se + 1;
			}

		}
	}
};
