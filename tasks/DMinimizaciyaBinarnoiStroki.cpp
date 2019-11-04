#include <iostream>

#include "../library/lib.hpp"

class DMinimizaciyaBinarnoiStroki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll k = read_ll();
			auto s = read_s();
			
			vll zp;
			
			forn(i, n){
				if(s[i] == '0')
					zp.pb(i);
			}
			
//			dbg(s);
//			dbg(zp);
			
			forn(i, zp.size()){
				ll mv = min(zp[i] - i, k);
				k -= mv;
				zp[i] -= mv;
			}
			
//			dbg(zp);
			
			string ans(n, '1');
			
			forr(z, zp){
				ans[z] = '0';
			}
			
			print ans;
		}
	}
};
